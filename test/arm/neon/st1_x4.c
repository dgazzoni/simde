
#include "test/test.h"
#define SIMDE_TEST_ARM_NEON_INSN st1_x4
#include "test-neon.h"
#include "../../../simde/arm/neon/st1_x4.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst1_f32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r[4][2];
    simde_float32 a[8];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(  -888.87), SIMDE_FLOAT32_C(   708.47) },
          { SIMDE_FLOAT32_C(  -777.85), SIMDE_FLOAT32_C(  -799.91) },
          { SIMDE_FLOAT32_C(   264.52), SIMDE_FLOAT32_C(  -980.05) },
          { SIMDE_FLOAT32_C(   823.07), SIMDE_FLOAT32_C(  -578.13) } },
      { SIMDE_FLOAT32_C(  -888.87), SIMDE_FLOAT32_C(   708.47), SIMDE_FLOAT32_C(  -777.85), SIMDE_FLOAT32_C(  -799.91),
        SIMDE_FLOAT32_C(   264.52), SIMDE_FLOAT32_C(  -980.05), SIMDE_FLOAT32_C(   823.07), SIMDE_FLOAT32_C(  -578.13) } },
    {
        { { SIMDE_FLOAT32_C(  -306.04), SIMDE_FLOAT32_C(   710.58) },
          { SIMDE_FLOAT32_C(   931.81), SIMDE_FLOAT32_C(  -975.48) },
          { SIMDE_FLOAT32_C(  -597.35), SIMDE_FLOAT32_C(  -797.34) },
          { SIMDE_FLOAT32_C(  -552.00), SIMDE_FLOAT32_C(   948.97) } },
      { SIMDE_FLOAT32_C(  -306.04), SIMDE_FLOAT32_C(   710.58), SIMDE_FLOAT32_C(   931.81), SIMDE_FLOAT32_C(  -975.48),
        SIMDE_FLOAT32_C(  -597.35), SIMDE_FLOAT32_C(  -797.34), SIMDE_FLOAT32_C(  -552.00), SIMDE_FLOAT32_C(   948.97) } },
    {
        { { SIMDE_FLOAT32_C(   491.44), SIMDE_FLOAT32_C(   902.32) },
          { SIMDE_FLOAT32_C(   651.63), SIMDE_FLOAT32_C(   -87.23) },
          { SIMDE_FLOAT32_C(  -496.24), SIMDE_FLOAT32_C(  -468.31) },
          { SIMDE_FLOAT32_C(  -590.91), SIMDE_FLOAT32_C(   295.14) } },
      { SIMDE_FLOAT32_C(   491.44), SIMDE_FLOAT32_C(   902.32), SIMDE_FLOAT32_C(   651.63), SIMDE_FLOAT32_C(   -87.23),
        SIMDE_FLOAT32_C(  -496.24), SIMDE_FLOAT32_C(  -468.31), SIMDE_FLOAT32_C(  -590.91), SIMDE_FLOAT32_C(   295.14) } },
    {
        { { SIMDE_FLOAT32_C(  -655.57), SIMDE_FLOAT32_C(  -620.90) },
          { SIMDE_FLOAT32_C(  -517.88), SIMDE_FLOAT32_C(  -603.98) },
          { SIMDE_FLOAT32_C(   181.30), SIMDE_FLOAT32_C(  -312.67) },
          { SIMDE_FLOAT32_C(   733.21), SIMDE_FLOAT32_C(   292.43) } },
      { SIMDE_FLOAT32_C(  -655.57), SIMDE_FLOAT32_C(  -620.90), SIMDE_FLOAT32_C(  -517.88), SIMDE_FLOAT32_C(  -603.98),
        SIMDE_FLOAT32_C(   181.30), SIMDE_FLOAT32_C(  -312.67), SIMDE_FLOAT32_C(   733.21), SIMDE_FLOAT32_C(   292.43) } },
    {
        { { SIMDE_FLOAT32_C(  -604.20), SIMDE_FLOAT32_C(   955.36) },
          { SIMDE_FLOAT32_C(   492.52), SIMDE_FLOAT32_C(   660.31) },
          { SIMDE_FLOAT32_C(   975.31), SIMDE_FLOAT32_C(   315.60) },
          { SIMDE_FLOAT32_C(  -917.81), SIMDE_FLOAT32_C(  -330.72) } },
      { SIMDE_FLOAT32_C(  -604.20), SIMDE_FLOAT32_C(   955.36), SIMDE_FLOAT32_C(   492.52), SIMDE_FLOAT32_C(   660.31),
        SIMDE_FLOAT32_C(   975.31), SIMDE_FLOAT32_C(   315.60), SIMDE_FLOAT32_C(  -917.81), SIMDE_FLOAT32_C(  -330.72) } },
    {
        { { SIMDE_FLOAT32_C(    26.18), SIMDE_FLOAT32_C(  -986.00) },
          { SIMDE_FLOAT32_C(  -306.20), SIMDE_FLOAT32_C(   428.83) },
          { SIMDE_FLOAT32_C(  -783.34), SIMDE_FLOAT32_C(   141.79) },
          { SIMDE_FLOAT32_C(   377.80), SIMDE_FLOAT32_C(   708.09) } },
      { SIMDE_FLOAT32_C(    26.18), SIMDE_FLOAT32_C(  -986.00), SIMDE_FLOAT32_C(  -306.20), SIMDE_FLOAT32_C(   428.83),
        SIMDE_FLOAT32_C(  -783.34), SIMDE_FLOAT32_C(   141.79), SIMDE_FLOAT32_C(   377.80), SIMDE_FLOAT32_C(   708.09) } },
    {
        { { SIMDE_FLOAT32_C(    44.11), SIMDE_FLOAT32_C(    29.43) },
          { SIMDE_FLOAT32_C(  -379.13), SIMDE_FLOAT32_C(   547.87) },
          { SIMDE_FLOAT32_C(   561.12), SIMDE_FLOAT32_C(    29.96) },
          { SIMDE_FLOAT32_C(  -156.99), SIMDE_FLOAT32_C(   905.55) } },
      { SIMDE_FLOAT32_C(    44.11), SIMDE_FLOAT32_C(    29.43), SIMDE_FLOAT32_C(  -379.13), SIMDE_FLOAT32_C(   547.87),
        SIMDE_FLOAT32_C(   561.12), SIMDE_FLOAT32_C(    29.96), SIMDE_FLOAT32_C(  -156.99), SIMDE_FLOAT32_C(   905.55) } },
    {
        { { SIMDE_FLOAT32_C(   409.06), SIMDE_FLOAT32_C(   325.12) },
          { SIMDE_FLOAT32_C(  -698.43), SIMDE_FLOAT32_C(  -409.64) },
          { SIMDE_FLOAT32_C(  -987.55), SIMDE_FLOAT32_C(  -965.21) },
          { SIMDE_FLOAT32_C(   882.79), SIMDE_FLOAT32_C(  -591.76) } },
      { SIMDE_FLOAT32_C(   409.06), SIMDE_FLOAT32_C(   325.12), SIMDE_FLOAT32_C(  -698.43), SIMDE_FLOAT32_C(  -409.64),
        SIMDE_FLOAT32_C(  -987.55), SIMDE_FLOAT32_C(  -965.21), SIMDE_FLOAT32_C(   882.79), SIMDE_FLOAT32_C(  -591.76) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x4_t r_ = { { simde_vld1_f32(test_vec[i].r[0]),
                                 simde_vld1_f32(test_vec[i].r[1]),
                                 simde_vld1_f32(test_vec[i].r[2]),
                                 simde_vld1_f32(test_vec[i].r[3]) } };

    simde_float32 a_[8];
    simde_vst1_f32_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t c = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t d = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_f32x2x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32 buf[8];
    simde_vst1_f32_x4(buf, e);

    simde_test_codegen_write_vf32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_f64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r[4][1];
    simde_float64 a[4];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(   990.15) },
          { SIMDE_FLOAT64_C(   375.32) },
          { SIMDE_FLOAT64_C(  -931.44) },
          { SIMDE_FLOAT64_C(   965.47) } },
      { SIMDE_FLOAT64_C(   990.15), SIMDE_FLOAT64_C(   375.32), SIMDE_FLOAT64_C(  -931.44), SIMDE_FLOAT64_C(   965.47) } },
    {
        { { SIMDE_FLOAT64_C(  -309.09) },
          { SIMDE_FLOAT64_C(  -849.25) },
          { SIMDE_FLOAT64_C(  -365.26) },
          { SIMDE_FLOAT64_C(   717.09) } },
      { SIMDE_FLOAT64_C(  -309.09), SIMDE_FLOAT64_C(  -849.25), SIMDE_FLOAT64_C(  -365.26), SIMDE_FLOAT64_C(   717.09) } },
    {
        { { SIMDE_FLOAT64_C(  -835.25) },
          { SIMDE_FLOAT64_C(   328.54) },
          { SIMDE_FLOAT64_C(   145.92) },
          { SIMDE_FLOAT64_C(  -618.59) } },
      { SIMDE_FLOAT64_C(  -835.25), SIMDE_FLOAT64_C(   328.54), SIMDE_FLOAT64_C(   145.92), SIMDE_FLOAT64_C(  -618.59) } },
    {
        { { SIMDE_FLOAT64_C(  -529.67) },
          { SIMDE_FLOAT64_C(  -476.28) },
          { SIMDE_FLOAT64_C(  -910.50) },
          { SIMDE_FLOAT64_C(   514.44) } },
      { SIMDE_FLOAT64_C(  -529.67), SIMDE_FLOAT64_C(  -476.28), SIMDE_FLOAT64_C(  -910.50), SIMDE_FLOAT64_C(   514.44) } },
    {
        { { SIMDE_FLOAT64_C(   553.15) },
          { SIMDE_FLOAT64_C(  -289.63) },
          { SIMDE_FLOAT64_C(    62.31) },
          { SIMDE_FLOAT64_C(   114.28) } },
      { SIMDE_FLOAT64_C(   553.15), SIMDE_FLOAT64_C(  -289.63), SIMDE_FLOAT64_C(    62.31), SIMDE_FLOAT64_C(   114.28) } },
    {
        { { SIMDE_FLOAT64_C(   740.34) },
          { SIMDE_FLOAT64_C(   905.32) },
          { SIMDE_FLOAT64_C(    19.83) },
          { SIMDE_FLOAT64_C(   149.40) } },
      { SIMDE_FLOAT64_C(   740.34), SIMDE_FLOAT64_C(   905.32), SIMDE_FLOAT64_C(    19.83), SIMDE_FLOAT64_C(   149.40) } },
    {
        { { SIMDE_FLOAT64_C(   230.44) },
          { SIMDE_FLOAT64_C(   321.40) },
          { SIMDE_FLOAT64_C(   739.76) },
          { SIMDE_FLOAT64_C(   242.89) } },
      { SIMDE_FLOAT64_C(   230.44), SIMDE_FLOAT64_C(   321.40), SIMDE_FLOAT64_C(   739.76), SIMDE_FLOAT64_C(   242.89) } },
    {
        { { SIMDE_FLOAT64_C(   356.19) },
          { SIMDE_FLOAT64_C(   622.55) },
          { SIMDE_FLOAT64_C(   651.14) },
          { SIMDE_FLOAT64_C(   346.34) } },
      { SIMDE_FLOAT64_C(   356.19), SIMDE_FLOAT64_C(   622.55), SIMDE_FLOAT64_C(   651.14), SIMDE_FLOAT64_C(   346.34) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x4_t r_ = { { simde_vld1_f64(test_vec[i].r[0]),
                                 simde_vld1_f64(test_vec[i].r[1]),
                                 simde_vld1_f64(test_vec[i].r[2]),
                                 simde_vld1_f64(test_vec[i].r[3]) } };

    simde_float64 a_[4];
    simde_vst1_f64_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t c = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t d = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_f64x1x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64 buf[4];
    simde_vst1_f64_x4(buf, e);

    simde_test_codegen_write_vf64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s8_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[4][8];
    int8_t a[32];
  } test_vec[] = {
    {
        { { -INT8_C(  60),  INT8_C(  53),  INT8_C( 119), -INT8_C(  27), -INT8_C( 113), -INT8_C(  14),  INT8_C(  22), -INT8_C(  97) },
          {  INT8_C(  55),  INT8_C(  89), -INT8_C( 119), -INT8_C( 114), -INT8_C( 103),  INT8_C(  60), -INT8_C(  26), -INT8_C( 100) },
          { -INT8_C( 115), -INT8_C(  38), -INT8_C(  93), -INT8_C(  67),  INT8_C(  31),  INT8_C(  19),  INT8_C(  66),  INT8_C( 107) },
          { -INT8_C(  54), -INT8_C(  94), -INT8_C(  65),  INT8_C(  45),  INT8_C(  61), -INT8_C(  46),  INT8_C(  56),  INT8_C(   1) } },
      { -INT8_C(  60),  INT8_C(  53),  INT8_C( 119), -INT8_C(  27), -INT8_C( 113), -INT8_C(  14),  INT8_C(  22), -INT8_C(  97),
         INT8_C(  55),  INT8_C(  89), -INT8_C( 119), -INT8_C( 114), -INT8_C( 103),  INT8_C(  60), -INT8_C(  26), -INT8_C( 100),
        -INT8_C( 115), -INT8_C(  38), -INT8_C(  93), -INT8_C(  67),  INT8_C(  31),  INT8_C(  19),  INT8_C(  66),  INT8_C( 107),
        -INT8_C(  54), -INT8_C(  94), -INT8_C(  65),  INT8_C(  45),  INT8_C(  61), -INT8_C(  46),  INT8_C(  56),  INT8_C(   1) } },
    {
        { {  INT8_C(   7), -INT8_C(  80), -INT8_C(  26), -INT8_C( 105), -INT8_C(  94), -INT8_C(   3),  INT8_C(  54), -INT8_C(  38) },
          {  INT8_C(  86), -INT8_C(  65),  INT8_C( 104), -INT8_C(  17), -INT8_C(   5),  INT8_C(  78), -INT8_C( 117), -INT8_C( 120) },
          {  INT8_C(  40),  INT8_C(  46),  INT8_C(  69),  INT8_C(  71),  INT8_C(  66), -INT8_C( 121), -INT8_C(  77),  INT8_C(  12) },
          {  INT8_C(  42),  INT8_C( 114),  INT8_C(  58),  INT8_C( 103),  INT8_C(  68),  INT8_C( 114),  INT8_C( 104),  INT8_C(  75) } },
      {  INT8_C(   7), -INT8_C(  80), -INT8_C(  26), -INT8_C( 105), -INT8_C(  94), -INT8_C(   3),  INT8_C(  54), -INT8_C(  38),
         INT8_C(  86), -INT8_C(  65),  INT8_C( 104), -INT8_C(  17), -INT8_C(   5),  INT8_C(  78), -INT8_C( 117), -INT8_C( 120),
         INT8_C(  40),  INT8_C(  46),  INT8_C(  69),  INT8_C(  71),  INT8_C(  66), -INT8_C( 121), -INT8_C(  77),  INT8_C(  12),
         INT8_C(  42),  INT8_C( 114),  INT8_C(  58),  INT8_C( 103),  INT8_C(  68),  INT8_C( 114),  INT8_C( 104),  INT8_C(  75) } },
    {
        { {  INT8_C(  34),  INT8_C(  78), -INT8_C(  30), -INT8_C(  59),  INT8_C(  75),  INT8_C(  24), -INT8_C(  97), -INT8_C(  95) },
          { -INT8_C(  41),  INT8_C(   7), -INT8_C( 112), -INT8_C(  46),  INT8_C(  85),  INT8_C(  28),  INT8_C(  90),  INT8_C( 125) },
          {  INT8_C(  74), -INT8_C(  96), -INT8_C(  60), -INT8_C( 116),  INT8_C(  39),  INT8_C( 119), -INT8_C( 103),  INT8_C(  81) },
          { -INT8_C(  23), -INT8_C(  45), -INT8_C(  72),  INT8_C(  45),  INT8_C(  69),  INT8_C(  32),  INT8_C( 121),  INT8_C( 104) } },
      {  INT8_C(  34),  INT8_C(  78), -INT8_C(  30), -INT8_C(  59),  INT8_C(  75),  INT8_C(  24), -INT8_C(  97), -INT8_C(  95),
        -INT8_C(  41),  INT8_C(   7), -INT8_C( 112), -INT8_C(  46),  INT8_C(  85),  INT8_C(  28),  INT8_C(  90),  INT8_C( 125),
         INT8_C(  74), -INT8_C(  96), -INT8_C(  60), -INT8_C( 116),  INT8_C(  39),  INT8_C( 119), -INT8_C( 103),  INT8_C(  81),
        -INT8_C(  23), -INT8_C(  45), -INT8_C(  72),  INT8_C(  45),  INT8_C(  69),  INT8_C(  32),  INT8_C( 121),  INT8_C( 104) } },
    {
        { {  INT8_C( 111),  INT8_C(  91),  INT8_C(  45), -INT8_C(  70),  INT8_C( 116), -INT8_C(  52),  INT8_C(  92),  INT8_C(  75) },
          { -INT8_C(  45), -INT8_C(  20),  INT8_C(  30),  INT8_C(  40),  INT8_C(   8),  INT8_C( 120), -INT8_C(  91),  INT8_C(  83) },
          {  INT8_C(  24),  INT8_C( 105), -INT8_C(  33),  INT8_C(  64), -INT8_C(  31),  INT8_C( 120), -INT8_C( 111), -INT8_C(  54) },
          {  INT8_C(  75),  INT8_C(  74), -INT8_C(   8), -INT8_C( 111),  INT8_C( 106),  INT8_C( 113), -INT8_C(   7), -INT8_C(  39) } },
      {  INT8_C( 111),  INT8_C(  91),  INT8_C(  45), -INT8_C(  70),  INT8_C( 116), -INT8_C(  52),  INT8_C(  92),  INT8_C(  75),
        -INT8_C(  45), -INT8_C(  20),  INT8_C(  30),  INT8_C(  40),  INT8_C(   8),  INT8_C( 120), -INT8_C(  91),  INT8_C(  83),
         INT8_C(  24),  INT8_C( 105), -INT8_C(  33),  INT8_C(  64), -INT8_C(  31),  INT8_C( 120), -INT8_C( 111), -INT8_C(  54),
         INT8_C(  75),  INT8_C(  74), -INT8_C(   8), -INT8_C( 111),  INT8_C( 106),  INT8_C( 113), -INT8_C(   7), -INT8_C(  39) } },
    {
        { { -INT8_C(  52),  INT8_C(  38), -INT8_C( 108),  INT8_C(  64), -INT8_C(  14), -INT8_C(  16), -INT8_C( 116), -INT8_C(  59) },
          { -INT8_C(  36), -INT8_C(  86), -INT8_C(  19), -INT8_C(  27),  INT8_C(  34), -INT8_C( 110),  INT8_C(  56),  INT8_C(  59) },
          { -INT8_C(   5),  INT8_C(  23),  INT8_C( 123), -INT8_C(  36), -INT8_C( 112),  INT8_C(  12), -INT8_C(  89), -INT8_C(  37) },
          {  INT8_C(  86), -INT8_C(  97),  INT8_C( 108), -INT8_C(  63),  INT8_C(  16),  INT8_C( 101), -INT8_C( 102), -INT8_C(  36) } },
      { -INT8_C(  52),  INT8_C(  38), -INT8_C( 108),  INT8_C(  64), -INT8_C(  14), -INT8_C(  16), -INT8_C( 116), -INT8_C(  59),
        -INT8_C(  36), -INT8_C(  86), -INT8_C(  19), -INT8_C(  27),  INT8_C(  34), -INT8_C( 110),  INT8_C(  56),  INT8_C(  59),
        -INT8_C(   5),  INT8_C(  23),  INT8_C( 123), -INT8_C(  36), -INT8_C( 112),  INT8_C(  12), -INT8_C(  89), -INT8_C(  37),
         INT8_C(  86), -INT8_C(  97),  INT8_C( 108), -INT8_C(  63),  INT8_C(  16),  INT8_C( 101), -INT8_C( 102), -INT8_C(  36) } },
    {
        { { -INT8_C( 117),  INT8_C(  46),  INT8_C(  29),  INT8_C( 125),  INT8_C(  30), -INT8_C(  87),  INT8_C(  66), -INT8_C(   5) },
          {  INT8_C(  83),  INT8_C(  47), -INT8_C(  32),  INT8_C( 117), -INT8_C(  63),  INT8_C(  24), -INT8_C(  80), -INT8_C(  67) },
          {  INT8_C(  47),  INT8_C(  43), -INT8_C( 103), -INT8_C(  65),  INT8_C(  56),  INT8_C(  64), -INT8_C( 101), -INT8_C( 114) },
          { -INT8_C(  33),  INT8_C(   7),  INT8_C(  79), -INT8_C(  17),  INT8_C( 109), -INT8_C(  22), -INT8_C(  52), -INT8_C(   8) } },
      { -INT8_C( 117),  INT8_C(  46),  INT8_C(  29),  INT8_C( 125),  INT8_C(  30), -INT8_C(  87),  INT8_C(  66), -INT8_C(   5),
         INT8_C(  83),  INT8_C(  47), -INT8_C(  32),  INT8_C( 117), -INT8_C(  63),  INT8_C(  24), -INT8_C(  80), -INT8_C(  67),
         INT8_C(  47),  INT8_C(  43), -INT8_C( 103), -INT8_C(  65),  INT8_C(  56),  INT8_C(  64), -INT8_C( 101), -INT8_C( 114),
        -INT8_C(  33),  INT8_C(   7),  INT8_C(  79), -INT8_C(  17),  INT8_C( 109), -INT8_C(  22), -INT8_C(  52), -INT8_C(   8) } },
    {
        { {  INT8_C(  24), -INT8_C(  23),  INT8_C( 118),  INT8_C(  55), -INT8_C( 110), -INT8_C(  72),  INT8_C(  50), -INT8_C(  27) },
          { -INT8_C(  24),  INT8_C(  18),  INT8_C(  90), -INT8_C(  87),  INT8_C(  42),  INT8_C(  11),  INT8_C( 102),  INT8_C(  89) },
          {  INT8_C(  54),  INT8_C(   0),  INT8_C(  25),  INT8_C( 110),  INT8_C(  64), -INT8_C(  76), -INT8_C(   3),  INT8_C(  32) },
          { -INT8_C(  69),  INT8_C(  76),  INT8_C(  15),  INT8_C(  40),  INT8_C(  54), -INT8_C(  37),  INT8_C(  33),  INT8_C(  79) } },
      {  INT8_C(  24), -INT8_C(  23),  INT8_C( 118),  INT8_C(  55), -INT8_C( 110), -INT8_C(  72),  INT8_C(  50), -INT8_C(  27),
        -INT8_C(  24),  INT8_C(  18),  INT8_C(  90), -INT8_C(  87),  INT8_C(  42),  INT8_C(  11),  INT8_C( 102),  INT8_C(  89),
         INT8_C(  54),  INT8_C(   0),  INT8_C(  25),  INT8_C( 110),  INT8_C(  64), -INT8_C(  76), -INT8_C(   3),  INT8_C(  32),
        -INT8_C(  69),  INT8_C(  76),  INT8_C(  15),  INT8_C(  40),  INT8_C(  54), -INT8_C(  37),  INT8_C(  33),  INT8_C(  79) } },
    {
        { { -INT8_C(  60), -INT8_C( 105), -INT8_C( 122),  INT8_C(  86),  INT8_C(  79), -INT8_C(  72),  INT8_C(  59),  INT8_C(  55) },
          { -INT8_C(  54), -INT8_C( 106), -INT8_C(  31), -INT8_C(  12), -INT8_C(  95),  INT8_C(  71),  INT8_C(  77), -INT8_C(  41) },
          {  INT8_C(  71),  INT8_C( 102),  INT8_C(  70), -INT8_C( 120),  INT8_C(  26),  INT8_C(  67), -INT8_C(  88), -INT8_C(  42) },
          { -INT8_C( 113), -INT8_C(  73), -INT8_C(   2), -INT8_C(  58), -INT8_C( 109),  INT8_C(  31),  INT8_C(  21),  INT8_C(  87) } },
      { -INT8_C(  60), -INT8_C( 105), -INT8_C( 122),  INT8_C(  86),  INT8_C(  79), -INT8_C(  72),  INT8_C(  59),  INT8_C(  55),
        -INT8_C(  54), -INT8_C( 106), -INT8_C(  31), -INT8_C(  12), -INT8_C(  95),  INT8_C(  71),  INT8_C(  77), -INT8_C(  41),
         INT8_C(  71),  INT8_C( 102),  INT8_C(  70), -INT8_C( 120),  INT8_C(  26),  INT8_C(  67), -INT8_C(  88), -INT8_C(  42),
        -INT8_C( 113), -INT8_C(  73), -INT8_C(   2), -INT8_C(  58), -INT8_C( 109),  INT8_C(  31),  INT8_C(  21),  INT8_C(  87) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x4_t r_ = { { simde_vld1_s8(test_vec[i].r[0]),
                              simde_vld1_s8(test_vec[i].r[1]),
                              simde_vld1_s8(test_vec[i].r[2]),
                              simde_vld1_s8(test_vec[i].r[3]) } };

    int8_t a_[32];
    simde_vst1_s8_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t c = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t d = simde_test_arm_neon_random_i8x8();
    simde_int8x8x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_i8x8x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    int8_t buf[32];
    simde_vst1_s8_x4(buf, e);

    simde_test_codegen_write_vi8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s16_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[4][4];
    int16_t a[16];
  } test_vec[] = {
    {
        { { -INT16_C( 25674),  INT16_C(  1710), -INT16_C(  5805),  INT16_C(  7485) },
          {  INT16_C(  7807),  INT16_C(  8209),  INT16_C( 24166), -INT16_C( 21000) },
          {  INT16_C( 16069), -INT16_C(  8395), -INT16_C(  8831),  INT16_C(  4277) },
          { -INT16_C( 19307),  INT16_C( 10454), -INT16_C(  5165), -INT16_C( 30081) } },
      { -INT16_C( 25674),  INT16_C(  1710), -INT16_C(  5805),  INT16_C(  7485),  INT16_C(  7807),  INT16_C(  8209),  INT16_C( 24166), -INT16_C( 21000),
         INT16_C( 16069), -INT16_C(  8395), -INT16_C(  8831),  INT16_C(  4277), -INT16_C( 19307),  INT16_C( 10454), -INT16_C(  5165), -INT16_C( 30081) } },
    {
        { {  INT16_C( 11654), -INT16_C(  9840), -INT16_C( 13033), -INT16_C( 26890) },
          {  INT16_C(  2028),  INT16_C( 21175), -INT16_C( 20634),  INT16_C( 11263) },
          {  INT16_C( 13805),  INT16_C( 28170), -INT16_C( 16366), -INT16_C( 22658) },
          {  INT16_C( 21876),  INT16_C( 18383),  INT16_C( 20288), -INT16_C( 14383) } },
      {  INT16_C( 11654), -INT16_C(  9840), -INT16_C( 13033), -INT16_C( 26890),  INT16_C(  2028),  INT16_C( 21175), -INT16_C( 20634),  INT16_C( 11263),
         INT16_C( 13805),  INT16_C( 28170), -INT16_C( 16366), -INT16_C( 22658),  INT16_C( 21876),  INT16_C( 18383),  INT16_C( 20288), -INT16_C( 14383) } },
    {
        { {  INT16_C( 24956), -INT16_C( 27744), -INT16_C( 26833),  INT16_C(  6954) },
          { -INT16_C(  7778),  INT16_C(  1133),  INT16_C( 27792),  INT16_C( 32047) },
          {  INT16_C( 15009), -INT16_C( 19221),  INT16_C( 27130),  INT16_C( 28251) },
          {  INT16_C( 11198), -INT16_C(    75), -INT16_C( 30854), -INT16_C(  2362) } },
      {  INT16_C( 24956), -INT16_C( 27744), -INT16_C( 26833),  INT16_C(  6954), -INT16_C(  7778),  INT16_C(  1133),  INT16_C( 27792),  INT16_C( 32047),
         INT16_C( 15009), -INT16_C( 19221),  INT16_C( 27130),  INT16_C( 28251),  INT16_C( 11198), -INT16_C(    75), -INT16_C( 30854), -INT16_C(  2362) } },
    {
        { {  INT16_C( 26344),  INT16_C(  6026), -INT16_C( 19203), -INT16_C( 25550) },
          { -INT16_C( 24683),  INT16_C(  9632), -INT16_C( 12276), -INT16_C( 21086) },
          { -INT16_C( 29430),  INT16_C(  1121), -INT16_C( 16906), -INT16_C( 19086) },
          {  INT16_C( 10216),  INT16_C( 25268),  INT16_C( 31406), -INT16_C( 26792) } },
      {  INT16_C( 26344),  INT16_C(  6026), -INT16_C( 19203), -INT16_C( 25550), -INT16_C( 24683),  INT16_C(  9632), -INT16_C( 12276), -INT16_C( 21086),
        -INT16_C( 29430),  INT16_C(  1121), -INT16_C( 16906), -INT16_C( 19086),  INT16_C( 10216),  INT16_C( 25268),  INT16_C( 31406), -INT16_C( 26792) } },
    {
        { { -INT16_C(  7456), -INT16_C(  8530), -INT16_C(  7786),  INT16_C( 11130) },
          {  INT16_C(  6784), -INT16_C( 29616), -INT16_C(  3350), -INT16_C(  3014) },
          { -INT16_C( 25729),  INT16_C( 30456),  INT16_C( 27224),  INT16_C( 16427) },
          { -INT16_C(  8302),  INT16_C( 16546), -INT16_C(  1191),  INT16_C( 14807) } },
      { -INT16_C(  7456), -INT16_C(  8530), -INT16_C(  7786),  INT16_C( 11130),  INT16_C(  6784), -INT16_C( 29616), -INT16_C(  3350), -INT16_C(  3014),
        -INT16_C( 25729),  INT16_C( 30456),  INT16_C( 27224),  INT16_C( 16427), -INT16_C(  8302),  INT16_C( 16546), -INT16_C(  1191),  INT16_C( 14807) } },
    {
        { { -INT16_C( 31011),  INT16_C( 29719), -INT16_C( 28313), -INT16_C(  6241) },
          { -INT16_C(  3924), -INT16_C( 27020), -INT16_C( 20766),  INT16_C( 25227) },
          { -INT16_C( 31927), -INT16_C( 23848),  INT16_C(  1006), -INT16_C( 32542) },
          { -INT16_C( 31262),  INT16_C( 15296), -INT16_C( 26496),  INT16_C( 23924) } },
      { -INT16_C( 31011),  INT16_C( 29719), -INT16_C( 28313), -INT16_C(  6241), -INT16_C(  3924), -INT16_C( 27020), -INT16_C( 20766),  INT16_C( 25227),
        -INT16_C( 31927), -INT16_C( 23848),  INT16_C(  1006), -INT16_C( 32542), -INT16_C( 31262),  INT16_C( 15296), -INT16_C( 26496),  INT16_C( 23924) } },
    {
        { { -INT16_C( 29666), -INT16_C( 31279),  INT16_C( 28957), -INT16_C( 13972) },
          { -INT16_C(  8095),  INT16_C( 17248), -INT16_C(  5234), -INT16_C( 10075) },
          {  INT16_C( 32110),  INT16_C( 23674),  INT16_C( 23680),  INT16_C( 25308) },
          { -INT16_C( 25119),  INT16_C( 24989),  INT16_C(  4661),  INT16_C( 21439) } },
      { -INT16_C( 29666), -INT16_C( 31279),  INT16_C( 28957), -INT16_C( 13972), -INT16_C(  8095),  INT16_C( 17248), -INT16_C(  5234), -INT16_C( 10075),
         INT16_C( 32110),  INT16_C( 23674),  INT16_C( 23680),  INT16_C( 25308), -INT16_C( 25119),  INT16_C( 24989),  INT16_C(  4661),  INT16_C( 21439) } },
    {
        { { -INT16_C( 28514), -INT16_C( 17448),  INT16_C( 17409),  INT16_C( 25221) },
          { -INT16_C(  6875), -INT16_C( 19546),  INT16_C( 19408),  INT16_C( 16011) },
          {  INT16_C(  1481),  INT16_C( 18843),  INT16_C( 30562),  INT16_C( 17324) },
          {  INT16_C( 18708),  INT16_C( 18853),  INT16_C( 25691), -INT16_C(  1636) } },
      { -INT16_C( 28514), -INT16_C( 17448),  INT16_C( 17409),  INT16_C( 25221), -INT16_C(  6875), -INT16_C( 19546),  INT16_C( 19408),  INT16_C( 16011),
         INT16_C(  1481),  INT16_C( 18843),  INT16_C( 30562),  INT16_C( 17324),  INT16_C( 18708),  INT16_C( 18853),  INT16_C( 25691), -INT16_C(  1636) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x4_t r_ = { { simde_vld1_s16(test_vec[i].r[0]),
                               simde_vld1_s16(test_vec[i].r[1]),
                               simde_vld1_s16(test_vec[i].r[2]),
                               simde_vld1_s16(test_vec[i].r[3]) } };

    int16_t a_[16];
    simde_vst1_s16_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t c = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t d = simde_test_arm_neon_random_i16x4();
    simde_int16x4x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_i16x4x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    int16_t buf[16];
    simde_vst1_s16_x4(buf, e);

    simde_test_codegen_write_vi16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[4][2];
    int32_t a[8];
  } test_vec[] = {
    {
        { { -INT32_C(   155880204), -INT32_C(   564643143) },
          { -INT32_C(   275644897),  INT32_C(   321723722) },
          { -INT32_C(  2074294238),  INT32_C(  1422395456) },
          { -INT32_C(  1382126254), -INT32_C(   978896175) } },
      { -INT32_C(   155880204), -INT32_C(   564643143), -INT32_C(   275644897),  INT32_C(   321723722), -INT32_C(  2074294238),  INT32_C(  1422395456), -INT32_C(  1382126254), -INT32_C(   978896175) } },
    {
        { {  INT32_C(  1757109423), -INT32_C(  1253698410) },
          {  INT32_C(  1554306834),  INT32_C(   393204212) },
          { -INT32_C(   627323750),  INT32_C(   640574420) },
          { -INT32_C(  1579889456), -INT32_C(  1234732281) } },
      {  INT32_C(  1757109423), -INT32_C(  1253698410),  INT32_C(  1554306834),  INT32_C(   393204212), -INT32_C(   627323750),  INT32_C(   640574420), -INT32_C(  1579889456), -INT32_C(  1234732281) } },
    {
        { {  INT32_C(  1830691543),  INT32_C(  1226990646) },
          {  INT32_C(   816170555),  INT32_C(   826742167) },
          { -INT32_C(  1257512223),  INT32_C(   383531590) },
          {  INT32_C(   230207494),  INT32_C(    46341931) } },
      {  INT32_C(  1830691543),  INT32_C(  1226990646),  INT32_C(   816170555),  INT32_C(   826742167), -INT32_C(  1257512223),  INT32_C(   383531590),  INT32_C(   230207494),  INT32_C(    46341931) } },
    {
        { {  INT32_C(  2020598081), -INT32_C(  2118020795) },
          { -INT32_C(   290363817),  INT32_C(  1545664635) },
          {  INT32_C(   538061786),  INT32_C(  1815604837) },
          { -INT32_C(   914755682),  INT32_C(  1338719502) } },
      {  INT32_C(  2020598081), -INT32_C(  2118020795), -INT32_C(   290363817),  INT32_C(  1545664635),  INT32_C(   538061786),  INT32_C(  1815604837), -INT32_C(   914755682),  INT32_C(  1338719502) } },
    {
        { {  INT32_C(  1690778142),  INT32_C(   585468107) },
          {  INT32_C(  1779472111),  INT32_C(  1757884558) },
          { -INT32_C(  1047930532),  INT32_C(  1697497287) },
          { -INT32_C(  1121015889),  INT32_C(    34404836) } },
      {  INT32_C(  1690778142),  INT32_C(   585468107),  INT32_C(  1779472111),  INT32_C(  1757884558), -INT32_C(  1047930532),  INT32_C(  1697497287), -INT32_C(  1121015889),  INT32_C(    34404836) } },
    {
        { { -INT32_C(    26815437),  INT32_C(  1260407644) },
          {  INT32_C(  1874211041), -INT32_C(  1109885599) },
          {  INT32_C(   494821718), -INT32_C(   796742623) },
          {  INT32_C(   932032595), -INT32_C(   600204887) } },
      { -INT32_C(    26815437),  INT32_C(  1260407644),  INT32_C(  1874211041), -INT32_C(  1109885599),  INT32_C(   494821718), -INT32_C(   796742623),  INT32_C(   932032595), -INT32_C(   600204887) } },
    {
        { { -INT32_C(   891641747), -INT32_C(   854197525) },
          { -INT32_C(  1958950102), -INT32_C(  1639443384) },
          { -INT32_C(  1766078603), -INT32_C(   966378125) },
          { -INT32_C(  1761741843), -INT32_C(    93178227) } },
      { -INT32_C(   891641747), -INT32_C(   854197525), -INT32_C(  1958950102), -INT32_C(  1639443384), -INT32_C(  1766078603), -INT32_C(   966378125), -INT32_C(  1761741843), -INT32_C(    93178227) } },
    {
        { { -INT32_C(  1027322666),  INT32_C(  1905252934) },
          { -INT32_C(   285422683),  INT32_C(  1435256288) },
          {  INT32_C(  2146191372),  INT32_C(  1933922949) },
          { -INT32_C(   754367930),  INT32_C(  1338866808) } },
      { -INT32_C(  1027322666),  INT32_C(  1905252934), -INT32_C(   285422683),  INT32_C(  1435256288),  INT32_C(  2146191372),  INT32_C(  1933922949), -INT32_C(   754367930),  INT32_C(  1338866808) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x4_t r_ = { { simde_vld1_s32(test_vec[i].r[0]),
                               simde_vld1_s32(test_vec[i].r[1]),
                               simde_vld1_s32(test_vec[i].r[2]),
                               simde_vld1_s32(test_vec[i].r[3]) } };

    int32_t a_[8];
    simde_vst1_s32_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t c = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t d = simde_test_arm_neon_random_i32x2();
    simde_int32x2x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_i32x2x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    int32_t buf[8];
    simde_vst1_s32_x4(buf, e);

    simde_test_codegen_write_vi32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r[4][1];
    int64_t a[4];
  } test_vec[] = {
    {
        { {  INT64_C( 1261184281633460936) },
          { -INT64_C( 3629465062852297621) },
          {  INT64_C( 2723712263114231252) },
          {  INT64_C( 1917344123157272275) } },
      {  INT64_C( 1261184281633460936), -INT64_C( 3629465062852297621),  INT64_C( 2723712263114231252),  INT64_C( 1917344123157272275) } },
    {
        { { -INT64_C( 5200064047555695528) },
          {  INT64_C( 3870180195189380390) },
          {  INT64_C( 7365174927807086897) },
          {  INT64_C( 5520654430802947633) } },
      { -INT64_C( 5200064047555695528),  INT64_C( 3870180195189380390),  INT64_C( 7365174927807086897),  INT64_C( 5520654430802947633) } },
    {
        { { -INT64_C( 7566638429043111943) },
          { -INT64_C( 3075620290571665221) },
          {  INT64_C( 7723140350262763316) },
          {  INT64_C( 2849525319494197322) } },
      { -INT64_C( 7566638429043111943), -INT64_C( 3075620290571665221),  INT64_C( 7723140350262763316),  INT64_C( 2849525319494197322) } },
    {
        { {  INT64_C( 4348905495741700947) },
          {  INT64_C( 4603709109053216874) },
          {  INT64_C( 3327937906290968713) },
          { -INT64_C(  257840247290979051) } },
      {  INT64_C( 4348905495741700947),  INT64_C( 4603709109053216874),  INT64_C( 3327937906290968713), -INT64_C(  257840247290979051) } },
    {
        { { -INT64_C( 6030009554954037101) },
          { -INT64_C( 2577011902698051086) },
          { -INT64_C( 8180843182068645019) },
          {  INT64_C( 7967497604580893932) } },
      { -INT64_C( 6030009554954037101), -INT64_C( 2577011902698051086), -INT64_C( 8180843182068645019),  INT64_C( 7967497604580893932) } },
    {
        { {  INT64_C( 6774210351291650580) },
          { -INT64_C( 4635163504467526531) },
          {  INT64_C(  495818284538023131) },
          {  INT64_C(  337258627198661476) } },
      {  INT64_C( 6774210351291650580), -INT64_C( 4635163504467526531),  INT64_C(  495818284538023131),  INT64_C(  337258627198661476) } },
    {
        { { -INT64_C( 9058325420480777856) },
          {  INT64_C( 1671679046805857561) },
          {  INT64_C( 2192211482088520267) },
          { -INT64_C( 5263850109382293249) } },
      { -INT64_C( 9058325420480777856),  INT64_C( 1671679046805857561),  INT64_C( 2192211482088520267), -INT64_C( 5263850109382293249) } },
    {
        { { -INT64_C( 4268026330833859267) },
          {  INT64_C( 7126217536348559249) },
          { -INT64_C( 7170797556664348509) },
          {  INT64_C( 2533977268612225597) } },
      { -INT64_C( 4268026330833859267),  INT64_C( 7126217536348559249), -INT64_C( 7170797556664348509),  INT64_C( 2533977268612225597) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x4_t r_ = { { simde_vld1_s64(test_vec[i].r[0]),
                               simde_vld1_s64(test_vec[i].r[1]),
                               simde_vld1_s64(test_vec[i].r[2]),
                               simde_vld1_s64(test_vec[i].r[3]) } };

    int64_t a_[4];
    simde_vst1_s64_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t c = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t d = simde_test_arm_neon_random_i64x1();
    simde_int64x1x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_i64x1x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    int64_t buf[4];
    simde_vst1_s64_x4(buf, e);

    simde_test_codegen_write_vi64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u8_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[4][8];
    uint8_t a[32];
  } test_vec[] = {
    {
        { { UINT8_C(204), UINT8_C(205), UINT8_C(101), UINT8_C(118), UINT8_C(185), UINT8_C( 42), UINT8_C( 58), UINT8_C( 75) },
          { UINT8_C( 65), UINT8_C(113), UINT8_C( 25), UINT8_C( 88), UINT8_C(218), UINT8_C(254), UINT8_C(187), UINT8_C(126) },
          { UINT8_C( 79), UINT8_C(131), UINT8_C(220), UINT8_C(236), UINT8_C(184), UINT8_C( 88), UINT8_C(136), UINT8_C(246) },
          { UINT8_C( 51), UINT8_C( 20), UINT8_C(106), UINT8_C( 25), UINT8_C(146), UINT8_C(148), UINT8_C( 61), UINT8_C( 94) } },
      { UINT8_C(204), UINT8_C(205), UINT8_C(101), UINT8_C(118), UINT8_C(185), UINT8_C( 42), UINT8_C( 58), UINT8_C( 75),
        UINT8_C( 65), UINT8_C(113), UINT8_C( 25), UINT8_C( 88), UINT8_C(218), UINT8_C(254), UINT8_C(187), UINT8_C(126),
        UINT8_C( 79), UINT8_C(131), UINT8_C(220), UINT8_C(236), UINT8_C(184), UINT8_C( 88), UINT8_C(136), UINT8_C(246),
        UINT8_C( 51), UINT8_C( 20), UINT8_C(106), UINT8_C( 25), UINT8_C(146), UINT8_C(148), UINT8_C( 61), UINT8_C( 94) } },
    {
        { { UINT8_C( 97), UINT8_C(162), UINT8_C(213), UINT8_C( 27), UINT8_C(204), UINT8_C( 15), UINT8_C(102), UINT8_C( 14) },
          { UINT8_C(129), UINT8_C(127), UINT8_C(102), UINT8_C( 91), UINT8_C(125), UINT8_C( 33), UINT8_C(217), UINT8_C(204) },
          { UINT8_C(165), UINT8_C(181), UINT8_C(184), UINT8_C( 93), UINT8_C( 14), UINT8_C( 65), UINT8_C( 83), UINT8_C( 65) },
          { UINT8_C( 85), UINT8_C(189), UINT8_C( 90), UINT8_C(231), UINT8_C( 82), UINT8_C(151), UINT8_C( 70), UINT8_C(179) } },
      { UINT8_C( 97), UINT8_C(162), UINT8_C(213), UINT8_C( 27), UINT8_C(204), UINT8_C( 15), UINT8_C(102), UINT8_C( 14),
        UINT8_C(129), UINT8_C(127), UINT8_C(102), UINT8_C( 91), UINT8_C(125), UINT8_C( 33), UINT8_C(217), UINT8_C(204),
        UINT8_C(165), UINT8_C(181), UINT8_C(184), UINT8_C( 93), UINT8_C( 14), UINT8_C( 65), UINT8_C( 83), UINT8_C( 65),
        UINT8_C( 85), UINT8_C(189), UINT8_C( 90), UINT8_C(231), UINT8_C( 82), UINT8_C(151), UINT8_C( 70), UINT8_C(179) } },
    {
        { { UINT8_C( 58), UINT8_C( 27), UINT8_C(206), UINT8_C(  6), UINT8_C( 42), UINT8_C( 52), UINT8_C( 20), UINT8_C(171) },
          { UINT8_C(179), UINT8_C(123), UINT8_C(  7), UINT8_C( 49), UINT8_C(156), UINT8_C(224), UINT8_C(253), UINT8_C( 65) },
          { UINT8_C(150), UINT8_C(182), UINT8_C(159), UINT8_C(164), UINT8_C(247), UINT8_C(242), UINT8_C(229), UINT8_C( 76) },
          { UINT8_C(176), UINT8_C( 63), UINT8_C( 51), UINT8_C(  2), UINT8_C(215), UINT8_C(121), UINT8_C(181), UINT8_C( 17) } },
      { UINT8_C( 58), UINT8_C( 27), UINT8_C(206), UINT8_C(  6), UINT8_C( 42), UINT8_C( 52), UINT8_C( 20), UINT8_C(171),
        UINT8_C(179), UINT8_C(123), UINT8_C(  7), UINT8_C( 49), UINT8_C(156), UINT8_C(224), UINT8_C(253), UINT8_C( 65),
        UINT8_C(150), UINT8_C(182), UINT8_C(159), UINT8_C(164), UINT8_C(247), UINT8_C(242), UINT8_C(229), UINT8_C( 76),
        UINT8_C(176), UINT8_C( 63), UINT8_C( 51), UINT8_C(  2), UINT8_C(215), UINT8_C(121), UINT8_C(181), UINT8_C( 17) } },
    {
        { { UINT8_C(148), UINT8_C(132), UINT8_C( 23), UINT8_C(191), UINT8_C(184), UINT8_C( 44), UINT8_C(106), UINT8_C(108) },
          { UINT8_C(167), UINT8_C(113), UINT8_C(157), UINT8_C( 67), UINT8_C( 82), UINT8_C(154), UINT8_C(133), UINT8_C(232) },
          { UINT8_C( 80), UINT8_C( 36), UINT8_C(140), UINT8_C( 71), UINT8_C( 22), UINT8_C(113), UINT8_C(147), UINT8_C(198) },
          { UINT8_C(176), UINT8_C(199), UINT8_C(200), UINT8_C(135), UINT8_C( 64), UINT8_C(126), UINT8_C(152), UINT8_C(213) } },
      { UINT8_C(148), UINT8_C(132), UINT8_C( 23), UINT8_C(191), UINT8_C(184), UINT8_C( 44), UINT8_C(106), UINT8_C(108),
        UINT8_C(167), UINT8_C(113), UINT8_C(157), UINT8_C( 67), UINT8_C( 82), UINT8_C(154), UINT8_C(133), UINT8_C(232),
        UINT8_C( 80), UINT8_C( 36), UINT8_C(140), UINT8_C( 71), UINT8_C( 22), UINT8_C(113), UINT8_C(147), UINT8_C(198),
        UINT8_C(176), UINT8_C(199), UINT8_C(200), UINT8_C(135), UINT8_C( 64), UINT8_C(126), UINT8_C(152), UINT8_C(213) } },
    {
        { { UINT8_C(  2), UINT8_C(176), UINT8_C(148), UINT8_C(186), UINT8_C(220), UINT8_C(254), UINT8_C( 38), UINT8_C(131) },
          { UINT8_C(112), UINT8_C(195), UINT8_C(198), UINT8_C(194), UINT8_C( 94), UINT8_C( 75), UINT8_C(170), UINT8_C(174) },
          { UINT8_C(111), UINT8_C( 54), UINT8_C(246), UINT8_C(134), UINT8_C(167), UINT8_C(137), UINT8_C( 76), UINT8_C( 87) },
          { UINT8_C( 80), UINT8_C( 21), UINT8_C(223), UINT8_C(145), UINT8_C(147), UINT8_C(119), UINT8_C(102), UINT8_C(149) } },
      { UINT8_C(  2), UINT8_C(176), UINT8_C(148), UINT8_C(186), UINT8_C(220), UINT8_C(254), UINT8_C( 38), UINT8_C(131),
        UINT8_C(112), UINT8_C(195), UINT8_C(198), UINT8_C(194), UINT8_C( 94), UINT8_C( 75), UINT8_C(170), UINT8_C(174),
        UINT8_C(111), UINT8_C( 54), UINT8_C(246), UINT8_C(134), UINT8_C(167), UINT8_C(137), UINT8_C( 76), UINT8_C( 87),
        UINT8_C( 80), UINT8_C( 21), UINT8_C(223), UINT8_C(145), UINT8_C(147), UINT8_C(119), UINT8_C(102), UINT8_C(149) } },
    {
        { { UINT8_C( 39), UINT8_C(250), UINT8_C( 79), UINT8_C(  3), UINT8_C(248), UINT8_C(118), UINT8_C(134), UINT8_C(104) },
          { UINT8_C( 57), UINT8_C( 77), UINT8_C( 42), UINT8_C(151), UINT8_C(152), UINT8_C(212), UINT8_C( 70), UINT8_C(  8) },
          { UINT8_C( 10), UINT8_C( 60), UINT8_C(142), UINT8_C(177), UINT8_C(197), UINT8_C(218), UINT8_C(  9), UINT8_C( 22) },
          { UINT8_C(239), UINT8_C(232), UINT8_C(167), UINT8_C(130), UINT8_C( 95), UINT8_C( 13), UINT8_C( 23), UINT8_C(135) } },
      { UINT8_C( 39), UINT8_C(250), UINT8_C( 79), UINT8_C(  3), UINT8_C(248), UINT8_C(118), UINT8_C(134), UINT8_C(104),
        UINT8_C( 57), UINT8_C( 77), UINT8_C( 42), UINT8_C(151), UINT8_C(152), UINT8_C(212), UINT8_C( 70), UINT8_C(  8),
        UINT8_C( 10), UINT8_C( 60), UINT8_C(142), UINT8_C(177), UINT8_C(197), UINT8_C(218), UINT8_C(  9), UINT8_C( 22),
        UINT8_C(239), UINT8_C(232), UINT8_C(167), UINT8_C(130), UINT8_C( 95), UINT8_C( 13), UINT8_C( 23), UINT8_C(135) } },
    {
        { { UINT8_C(  7), UINT8_C(103), UINT8_C(138),    UINT8_MAX, UINT8_C(221), UINT8_C( 17), UINT8_C(104), UINT8_C( 22) },
          { UINT8_C( 94), UINT8_C(146), UINT8_C(174), UINT8_C(246), UINT8_C(103), UINT8_C(244), UINT8_C(254), UINT8_C(113) },
          { UINT8_C( 48), UINT8_C(140), UINT8_C( 35), UINT8_C(245), UINT8_C(103), UINT8_C( 44), UINT8_C( 11), UINT8_C( 86) },
          { UINT8_C( 20), UINT8_C(178), UINT8_C(217), UINT8_C(115), UINT8_C(191), UINT8_C(240), UINT8_C(250), UINT8_C(198) } },
      { UINT8_C(  7), UINT8_C(103), UINT8_C(138),    UINT8_MAX, UINT8_C(221), UINT8_C( 17), UINT8_C(104), UINT8_C( 22),
        UINT8_C( 94), UINT8_C(146), UINT8_C(174), UINT8_C(246), UINT8_C(103), UINT8_C(244), UINT8_C(254), UINT8_C(113),
        UINT8_C( 48), UINT8_C(140), UINT8_C( 35), UINT8_C(245), UINT8_C(103), UINT8_C( 44), UINT8_C( 11), UINT8_C( 86),
        UINT8_C( 20), UINT8_C(178), UINT8_C(217), UINT8_C(115), UINT8_C(191), UINT8_C(240), UINT8_C(250), UINT8_C(198) } },
    {
        { { UINT8_C( 87), UINT8_C(133), UINT8_C(198), UINT8_C( 52), UINT8_C(150), UINT8_C( 46), UINT8_C( 75), UINT8_C(244) },
          { UINT8_C(192), UINT8_C(249), UINT8_C(234), UINT8_C( 39), UINT8_C(237), UINT8_C(233), UINT8_C(153), UINT8_C( 29) },
          { UINT8_C(117), UINT8_C(188), UINT8_C( 18), UINT8_C(220), UINT8_C(232), UINT8_C( 30), UINT8_C( 51), UINT8_C(252) },
          { UINT8_C(208), UINT8_C( 12), UINT8_C(111), UINT8_C(144), UINT8_C(252), UINT8_C(106), UINT8_C( 86), UINT8_C( 84) } },
      { UINT8_C( 87), UINT8_C(133), UINT8_C(198), UINT8_C( 52), UINT8_C(150), UINT8_C( 46), UINT8_C( 75), UINT8_C(244),
        UINT8_C(192), UINT8_C(249), UINT8_C(234), UINT8_C( 39), UINT8_C(237), UINT8_C(233), UINT8_C(153), UINT8_C( 29),
        UINT8_C(117), UINT8_C(188), UINT8_C( 18), UINT8_C(220), UINT8_C(232), UINT8_C( 30), UINT8_C( 51), UINT8_C(252),
        UINT8_C(208), UINT8_C( 12), UINT8_C(111), UINT8_C(144), UINT8_C(252), UINT8_C(106), UINT8_C( 86), UINT8_C( 84) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x4_t r_ = { { simde_vld1_u8(test_vec[i].r[0]),
                               simde_vld1_u8(test_vec[i].r[1]),
                               simde_vld1_u8(test_vec[i].r[2]),
                               simde_vld1_u8(test_vec[i].r[3]) } };

    uint8_t a_[32];
    simde_vst1_u8_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t c = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t d = simde_test_arm_neon_random_u8x8();
    simde_uint8x8x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_u8x8x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    uint8_t buf[32];
    simde_vst1_u8_x4(buf, e);

    simde_test_codegen_write_vu8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u16_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[4][4];
    uint16_t a[16];
  } test_vec[] = {
    {
        { { UINT16_C( 7407), UINT16_C(34184), UINT16_C(54090), UINT16_C( 2937) },
          { UINT16_C(25548), UINT16_C(47410), UINT16_C(52044), UINT16_C(49878) },
          { UINT16_C(59783), UINT16_C(28574), UINT16_C(53511), UINT16_C(55147) },
          { UINT16_C(56285), UINT16_C(55911), UINT16_C(48709), UINT16_C(13358) } },
      { UINT16_C( 7407), UINT16_C(34184), UINT16_C(54090), UINT16_C( 2937), UINT16_C(25548), UINT16_C(47410), UINT16_C(52044), UINT16_C(49878),
        UINT16_C(59783), UINT16_C(28574), UINT16_C(53511), UINT16_C(55147), UINT16_C(56285), UINT16_C(55911), UINT16_C(48709), UINT16_C(13358) } },
    {
        { { UINT16_C(46810), UINT16_C( 9657), UINT16_C(12938), UINT16_C(22064) },
          { UINT16_C(25237), UINT16_C(57872), UINT16_C(58926), UINT16_C(46500) },
          { UINT16_C(17103), UINT16_C(54821), UINT16_C(36884), UINT16_C(61870) },
          { UINT16_C( 5483), UINT16_C(45259), UINT16_C(63955), UINT16_C(44772) } },
      { UINT16_C(46810), UINT16_C( 9657), UINT16_C(12938), UINT16_C(22064), UINT16_C(25237), UINT16_C(57872), UINT16_C(58926), UINT16_C(46500),
        UINT16_C(17103), UINT16_C(54821), UINT16_C(36884), UINT16_C(61870), UINT16_C( 5483), UINT16_C(45259), UINT16_C(63955), UINT16_C(44772) } },
    {
        { { UINT16_C(40368), UINT16_C(15059), UINT16_C(  975), UINT16_C(26000) },
          { UINT16_C(41061), UINT16_C(37703), UINT16_C(60295), UINT16_C(22089) },
          { UINT16_C(28205), UINT16_C(16685), UINT16_C(56318), UINT16_C(27187) },
          { UINT16_C(65264), UINT16_C(50202), UINT16_C(65528), UINT16_C(43122) } },
      { UINT16_C(40368), UINT16_C(15059), UINT16_C(  975), UINT16_C(26000), UINT16_C(41061), UINT16_C(37703), UINT16_C(60295), UINT16_C(22089),
        UINT16_C(28205), UINT16_C(16685), UINT16_C(56318), UINT16_C(27187), UINT16_C(65264), UINT16_C(50202), UINT16_C(65528), UINT16_C(43122) } },
    {
        { { UINT16_C(17820), UINT16_C(27874), UINT16_C(29256), UINT16_C(44497) },
          { UINT16_C( 6163), UINT16_C(39489), UINT16_C(35331), UINT16_C(12528) },
          { UINT16_C( 7672), UINT16_C(63090), UINT16_C(42488), UINT16_C(59744) },
          { UINT16_C(31651), UINT16_C(39853), UINT16_C( 8058), UINT16_C( 5699) } },
      { UINT16_C(17820), UINT16_C(27874), UINT16_C(29256), UINT16_C(44497), UINT16_C( 6163), UINT16_C(39489), UINT16_C(35331), UINT16_C(12528),
        UINT16_C( 7672), UINT16_C(63090), UINT16_C(42488), UINT16_C(59744), UINT16_C(31651), UINT16_C(39853), UINT16_C( 8058), UINT16_C( 5699) } },
    {
        { { UINT16_C( 9572), UINT16_C(44162), UINT16_C(21400), UINT16_C(43865) },
          { UINT16_C(39531), UINT16_C(28229), UINT16_C(13604), UINT16_C( 7327) },
          { UINT16_C( 4435), UINT16_C(19219), UINT16_C(29622), UINT16_C(22836) },
          { UINT16_C(57838), UINT16_C(26869), UINT16_C(14336), UINT16_C(25727) } },
      { UINT16_C( 9572), UINT16_C(44162), UINT16_C(21400), UINT16_C(43865), UINT16_C(39531), UINT16_C(28229), UINT16_C(13604), UINT16_C( 7327),
        UINT16_C( 4435), UINT16_C(19219), UINT16_C(29622), UINT16_C(22836), UINT16_C(57838), UINT16_C(26869), UINT16_C(14336), UINT16_C(25727) } },
    {
        { { UINT16_C(  350), UINT16_C(62992), UINT16_C(27221), UINT16_C(49313) },
          { UINT16_C(58884), UINT16_C(10543), UINT16_C(52763), UINT16_C(28229) },
          { UINT16_C(22751), UINT16_C(38330), UINT16_C(61132), UINT16_C(47854) },
          { UINT16_C(58320), UINT16_C(53283), UINT16_C(41500), UINT16_C(31285) } },
      { UINT16_C(  350), UINT16_C(62992), UINT16_C(27221), UINT16_C(49313), UINT16_C(58884), UINT16_C(10543), UINT16_C(52763), UINT16_C(28229),
        UINT16_C(22751), UINT16_C(38330), UINT16_C(61132), UINT16_C(47854), UINT16_C(58320), UINT16_C(53283), UINT16_C(41500), UINT16_C(31285) } },
    {
        { { UINT16_C(17827), UINT16_C(63600), UINT16_C( 4527), UINT16_C(46265) },
          { UINT16_C(59639), UINT16_C( 4829), UINT16_C( 8886), UINT16_C(38273) },
          { UINT16_C(15227), UINT16_C(18218), UINT16_C( 6185), UINT16_C(63745) },
          { UINT16_C( 9468), UINT16_C( 6346), UINT16_C(65478), UINT16_C(27282) } },
      { UINT16_C(17827), UINT16_C(63600), UINT16_C( 4527), UINT16_C(46265), UINT16_C(59639), UINT16_C( 4829), UINT16_C( 8886), UINT16_C(38273),
        UINT16_C(15227), UINT16_C(18218), UINT16_C( 6185), UINT16_C(63745), UINT16_C( 9468), UINT16_C( 6346), UINT16_C(65478), UINT16_C(27282) } },
    {
        { { UINT16_C(  580), UINT16_C(62562), UINT16_C( 6931), UINT16_C( 2728) },
          { UINT16_C(34051), UINT16_C(47388), UINT16_C(40359), UINT16_C( 8782) },
          { UINT16_C(30936), UINT16_C(  617), UINT16_C(27537), UINT16_C(36347) },
          { UINT16_C(50575), UINT16_C(22181), UINT16_C(14276), UINT16_C( 2496) } },
      { UINT16_C(  580), UINT16_C(62562), UINT16_C( 6931), UINT16_C( 2728), UINT16_C(34051), UINT16_C(47388), UINT16_C(40359), UINT16_C( 8782),
        UINT16_C(30936), UINT16_C(  617), UINT16_C(27537), UINT16_C(36347), UINT16_C(50575), UINT16_C(22181), UINT16_C(14276), UINT16_C( 2496) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x4_t r_ = { { simde_vld1_u16(test_vec[i].r[0]),
                                simde_vld1_u16(test_vec[i].r[1]),
                                simde_vld1_u16(test_vec[i].r[2]),
                                simde_vld1_u16(test_vec[i].r[3]) } };

    uint16_t a_[16];
    simde_vst1_u16_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t c = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t d = simde_test_arm_neon_random_u16x4();
    simde_uint16x4x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_u16x4x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    uint16_t buf[16];
    simde_vst1_u16_x4(buf, e);

    simde_test_codegen_write_vu16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[4][2];
    uint32_t a[8];
  } test_vec[] = {
    {
        { { UINT32_C(1291657785), UINT32_C(1096197438) },
          { UINT32_C(3522916906), UINT32_C(3908323600) },
          { UINT32_C(1407868354), UINT32_C(1491134152) },
          { UINT32_C(1890485675), UINT32_C(4118376124) } },
      { UINT32_C(1291657785), UINT32_C(1096197438), UINT32_C(3522916906), UINT32_C(3908323600), UINT32_C(1407868354), UINT32_C(1491134152), UINT32_C(1890485675), UINT32_C(4118376124) } },
    {
        { { UINT32_C(3460396688), UINT32_C(1158715163) },
          { UINT32_C( 420875017), UINT32_C( 369232468) },
          { UINT32_C( 812248168), UINT32_C(2122861010) },
          { UINT32_C(2330867406), UINT32_C( 897542052) } },
      { UINT32_C(3460396688), UINT32_C(1158715163), UINT32_C( 420875017), UINT32_C( 369232468), UINT32_C( 812248168), UINT32_C(2122861010), UINT32_C(2330867406), UINT32_C( 897542052) } },
    {
        { { UINT32_C(4160995549), UINT32_C(1631392599) },
          { UINT32_C(1937396510), UINT32_C(3330899038) },
          { UINT32_C(1006039913), UINT32_C( 196706108) },
          { UINT32_C(1519757237), UINT32_C(3952022798) } },
      { UINT32_C(4160995549), UINT32_C(1631392599), UINT32_C(1937396510), UINT32_C(3330899038), UINT32_C(1006039913), UINT32_C( 196706108), UINT32_C(1519757237), UINT32_C(3952022798) } },
    {
        { { UINT32_C( 769888981), UINT32_C(3297648806) },
          { UINT32_C(3526822004), UINT32_C(4002988421) },
          { UINT32_C(4029255348), UINT32_C(3288064781) },
          { UINT32_C(2568851850), UINT32_C(2072292518) } },
      { UINT32_C( 769888981), UINT32_C(3297648806), UINT32_C(3526822004), UINT32_C(4002988421), UINT32_C(4029255348), UINT32_C(3288064781), UINT32_C(2568851850), UINT32_C(2072292518) } },
    {
        { { UINT32_C(3836241982), UINT32_C(4238947976) },
          { UINT32_C(3301892159), UINT32_C(1437755041) },
          { UINT32_C(  38198261), UINT32_C(1237664190) },
          { UINT32_C(2028135122), UINT32_C(3455346318) } },
      { UINT32_C(3836241982), UINT32_C(4238947976), UINT32_C(3301892159), UINT32_C(1437755041), UINT32_C(  38198261), UINT32_C(1237664190), UINT32_C(2028135122), UINT32_C(3455346318) } },
    {
        { { UINT32_C(1471257806), UINT32_C( 307452627) },
          { UINT32_C(3705020987), UINT32_C(2100463752) },
          { UINT32_C( 578844771), UINT32_C(2355840441) },
          { UINT32_C(3053735208), UINT32_C(2189686963) } },
      { UINT32_C(1471257806), UINT32_C( 307452627), UINT32_C(3705020987), UINT32_C(2100463752), UINT32_C( 578844771), UINT32_C(2355840441), UINT32_C(3053735208), UINT32_C(2189686963) } },
    {
        { { UINT32_C(1759065493), UINT32_C(3397004431) },
          { UINT32_C(3618066510), UINT32_C( 995416536) },
          { UINT32_C( 173921361), UINT32_C(1117177882) },
          { UINT32_C(3388513045), UINT32_C( 676035731) } },
      { UINT32_C(1759065493), UINT32_C(3397004431), UINT32_C(3618066510), UINT32_C( 995416536), UINT32_C( 173921361), UINT32_C(1117177882), UINT32_C(3388513045), UINT32_C( 676035731) } },
    {
        { { UINT32_C(1083188401), UINT32_C(2668300880) },
          { UINT32_C( 846639706), UINT32_C(3698248331) },
          { UINT32_C(3118910367), UINT32_C(2851831188) },
          { UINT32_C(2876437272), UINT32_C( 550813039) } },
      { UINT32_C(1083188401), UINT32_C(2668300880), UINT32_C( 846639706), UINT32_C(3698248331), UINT32_C(3118910367), UINT32_C(2851831188), UINT32_C(2876437272), UINT32_C( 550813039) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x4_t r_ = { { simde_vld1_u32(test_vec[i].r[0]),
                                simde_vld1_u32(test_vec[i].r[1]),
                                simde_vld1_u32(test_vec[i].r[2]),
                                simde_vld1_u32(test_vec[i].r[3]) } };

    uint32_t a_[8];
    simde_vst1_u32_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t c = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t d = simde_test_arm_neon_random_u32x2();
    simde_uint32x2x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_u32x2x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    uint32_t buf[8];
    simde_vst1_u32_x4(buf, e);

    simde_test_codegen_write_vu32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r[4][1];
    uint64_t a[4];
  } test_vec[] = {
    {
        { { UINT64_C(14542523896598455521) },
          { UINT64_C(12719689346676705054) },
          { UINT64_C(   32480573296044853) },
          { UINT64_C( 9577046048521381208) } },
      { UINT64_C(14542523896598455521), UINT64_C(12719689346676705054), UINT64_C(   32480573296044853), UINT64_C( 9577046048521381208) } },
    {
        { { UINT64_C(15212464329190689252) },
          { UINT64_C(13299131365543647694) },
          { UINT64_C(13138677273433668204) },
          { UINT64_C( 7350550248164295130) } },
      { UINT64_C(15212464329190689252), UINT64_C(13299131365543647694), UINT64_C(13138677273433668204), UINT64_C( 7350550248164295130) } },
    {
        { { UINT64_C( 1024523012306221231) },
          { UINT64_C( 2318086846211339247) },
          { UINT64_C( 8975335007655931257) },
          { UINT64_C( 2428843666941021388) } },
      { UINT64_C( 1024523012306221231), UINT64_C( 2318086846211339247), UINT64_C( 8975335007655931257), UINT64_C( 2428843666941021388) } },
    {
        { { UINT64_C( 3675988725210639796) },
          { UINT64_C(16808508513841508719) },
          { UINT64_C( 5808605048304941438) },
          { UINT64_C( 5183171011618444891) } },
      { UINT64_C( 3675988725210639796), UINT64_C(16808508513841508719), UINT64_C( 5808605048304941438), UINT64_C( 5183171011618444891) } },
    {
        { { UINT64_C(11400649353367090112) },
          { UINT64_C( 3209382832522779952) },
          { UINT64_C(17695462734621854653) },
          { UINT64_C( 4853104150470340735) } },
      { UINT64_C(11400649353367090112), UINT64_C( 3209382832522779952), UINT64_C(17695462734621854653), UINT64_C( 4853104150470340735) } },
    {
        { { UINT64_C(  283866222607963171) },
          { UINT64_C( 8302154693671629148) },
          { UINT64_C(17007639947772199800) },
          { UINT64_C(11258250824909769079) } },
      { UINT64_C(  283866222607963171), UINT64_C( 8302154693671629148), UINT64_C(17007639947772199800), UINT64_C(11258250824909769079) } },
    {
        { { UINT64_C( 6827982613444986091) },
          { UINT64_C(  844601480222172559) },
          { UINT64_C( 3061363299852315683) },
          { UINT64_C(13548061131060574958) } },
      { UINT64_C( 6827982613444986091), UINT64_C(  844601480222172559), UINT64_C( 3061363299852315683), UINT64_C(13548061131060574958) } },
    {
        { { UINT64_C( 7009356742278247397) },
          { UINT64_C( 8232402338135322529) },
          { UINT64_C( 8117595947971796170) },
          { UINT64_C( 1262938830447102968) } },
      { UINT64_C( 7009356742278247397), UINT64_C( 8232402338135322529), UINT64_C( 8117595947971796170), UINT64_C( 1262938830447102968) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x4_t r_ = { { simde_vld1_u64(test_vec[i].r[0]),
                                simde_vld1_u64(test_vec[i].r[1]),
                                simde_vld1_u64(test_vec[i].r[2]),
                                simde_vld1_u64(test_vec[i].r[3]) } };

    uint64_t a_[4];
    simde_vst1_u64_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t c = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t d = simde_test_arm_neon_random_u64x1();
    simde_uint64x1x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_u64x1x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    uint64_t buf[4];
    simde_vst1_u64_x4(buf, e);

    simde_test_codegen_write_vu64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f64_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s8_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s16_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s64_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u8_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u16_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u64_x4)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
