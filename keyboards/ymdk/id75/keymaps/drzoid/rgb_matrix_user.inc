// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(my_fire_effect)
RGB_MATRIX_EFFECT(my_cool_effect)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
static bool my_cool_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
  }
  return rgb_matrix_check_finished_leds(led_max);
}

// e.g: A more complex effect, relying on external methods and state, with
// dedicated init and run methods

static const int max_flame_height = 1000;
static const int max_heat_spots = 1000;
static const int min_x_attenuation = 500;
static const int min_flame_height = 300;
static const int min_heat_spots = 300;
static const int max_x_attenuation = 500;

int init_flame_height = 1;
int init_heat_spots = 1000;
int init_x_attenuation = 5000;
int speed = 15000;
int starting_speed = 1000;
int periodicity = 7200000;

int apow(int a, int b) {
  return 1000 + (a - 1000) * b / 1000;
}

int int_lerp(int a, int b, int c) {
  if(c <= 0)
      return a;
  if(c >= 1000)
      return b;
  return (a * (1000 - c) + b * c) / 1000;
}

unsigned int rnd(int x, int y) {
  int X = x ^ 64228;
  int Y = y ^ 61356;
  return (((((X * 71521)+ (Y * 13547))^ 35135) % 1000) + 1000) % 1000;
}

int noise(int X, int Y, int T, int flame_height, int heat_spots, int x_attenuation) {
  int x = X;
  int n = 0;
  int attenuation = (MATRIX_ROWS - Y) * 1000 / MATRIX_ROWS * 1000 / flame_height
    + (x_attenuation == 0 ? 0
    : MAX(0, apow(1000 - (X + 1) * (MATRIX_COLS - X) * 4000 / ((MATRIX_COLS + 2) * (MATRIX_COLS+ 2)), 1000000 / x_attenuation)));

  int sum_coeff = 0;
  for(int i = 8 ; i > 0 ; i >>= 1) {
    int y = Y + T * 8 / i;
    int rnd_00 = rnd(x / i, y / i);
    int rnd_01 = rnd(x / i, y / i + 1);
    int rnd_10 = rnd(x / i + 1, y / i);
    int rnd_11 = rnd(x / i + 1, y / i + 1);
    int coeff = i;
    int dx = x % i;
    int dy = y % i;
    n += ((rnd_00 * (i - dx) + rnd_10 * dx) * (i - dy)
        + (rnd_01 * (i - dx) + rnd_11 * dx) * dy)
    * coeff / (i * i);
    sum_coeff += coeff;
  }
  return MAX(0, apow(n / sum_coeff, 1000000 / heat_spots * 1000 / (attenuation + 1000)) - attenuation);
}

static void my_fire_effect_init(effect_params_t* params) {
}

static bool my_fire_effect_run(effect_params_t* params) {
  unsigned long timer = g_rgb_timer/10;
  int begin_time = timer > starting_speed ? 1000 : (int) (timer * 1000 / starting_speed);

  // must be signed int
  int periodic_time = (int) (timer % periodicity);
  periodic_time = periodic_time * 1000 / periodicity;
  if(periodic_time > 500)
      periodic_time = 1000 - periodic_time;

  int flame_height = int_lerp(int_lerp(init_flame_height, max_flame_height, begin_time), min_flame_height, periodic_time);
  int heat_spots = int_lerp(int_lerp(init_heat_spots, max_heat_spots, begin_time), min_heat_spots, periodic_time);
  int x_attenuation = int_lerp(int_lerp(init_x_attenuation, min_x_attenuation, begin_time), max_x_attenuation, periodic_time);

  for (uint8_t col = 0; col < MATRIX_COLS; col++) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
      int heat = noise(col, row, (int) (timer * speed / 1000), flame_height, heat_spots, x_attenuation);
      int r = MIN(255, (int) (heat * 255 / 333));
      int g = MIN(255, MAX(0, (int) ((heat - 333) * 255 / 333)));
      int b = MIN(255, MAX(0, (int) ((heat - 667) * 255 / 333)));
      int i = row * MATRIX_COLS + col;
      rgb_matrix_set_color(i, r,g,b);
    }
  }
  return false;

static bool my_fire_effect(effect_params_t* params) {
  if (params->init) my_fire_effect_init(params);
  return my_fire_effect_run(params);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
