
#include "test/test.h"
#define SIMDE_TEST_ARM_NEON_INSN st1_x3
#include "test-neon.h"
#include "../../../simde/arm/neon/st1_x3.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst1_f32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r[3][2];
    simde_float32 a[6];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(   146.01), SIMDE_FLOAT32_C(  -889.05) },
          { SIMDE_FLOAT32_C(   962.13), SIMDE_FLOAT32_C(   530.25) },
          { SIMDE_FLOAT32_C(  -129.82), SIMDE_FLOAT32_C(   952.84) } },
      { SIMDE_FLOAT32_C(   146.01), SIMDE_FLOAT32_C(  -889.05), SIMDE_FLOAT32_C(   962.13), SIMDE_FLOAT32_C(   530.25),
        SIMDE_FLOAT32_C(  -129.82), SIMDE_FLOAT32_C(   952.84) } },
    {
        { { SIMDE_FLOAT32_C(  -520.62), SIMDE_FLOAT32_C(   248.83) },
          { SIMDE_FLOAT32_C(  -761.06), SIMDE_FLOAT32_C(  -988.57) },
          { SIMDE_FLOAT32_C(  -830.55), SIMDE_FLOAT32_C(  -351.49) } },
      { SIMDE_FLOAT32_C(  -520.62), SIMDE_FLOAT32_C(   248.83), SIMDE_FLOAT32_C(  -761.06), SIMDE_FLOAT32_C(  -988.57),
        SIMDE_FLOAT32_C(  -830.55), SIMDE_FLOAT32_C(  -351.49) } },
    {
        { { SIMDE_FLOAT32_C(  -860.29), SIMDE_FLOAT32_C(   301.63) },
          { SIMDE_FLOAT32_C(   467.74), SIMDE_FLOAT32_C(   663.11) },
          { SIMDE_FLOAT32_C(   572.60), SIMDE_FLOAT32_C(    37.59) } },
      { SIMDE_FLOAT32_C(  -860.29), SIMDE_FLOAT32_C(   301.63), SIMDE_FLOAT32_C(   467.74), SIMDE_FLOAT32_C(   663.11),
        SIMDE_FLOAT32_C(   572.60), SIMDE_FLOAT32_C(    37.59) } },
    {
        { { SIMDE_FLOAT32_C(     3.56), SIMDE_FLOAT32_C(   801.90) },
          { SIMDE_FLOAT32_C(   170.26), SIMDE_FLOAT32_C(  -137.39) },
          { SIMDE_FLOAT32_C(   789.73), SIMDE_FLOAT32_C(   293.65) } },
      { SIMDE_FLOAT32_C(     3.56), SIMDE_FLOAT32_C(   801.90), SIMDE_FLOAT32_C(   170.26), SIMDE_FLOAT32_C(  -137.39),
        SIMDE_FLOAT32_C(   789.73), SIMDE_FLOAT32_C(   293.65) } },
    {
        { { SIMDE_FLOAT32_C(   296.66), SIMDE_FLOAT32_C(  -773.54) },
          { SIMDE_FLOAT32_C(   693.95), SIMDE_FLOAT32_C(   373.73) },
          { SIMDE_FLOAT32_C(    48.70), SIMDE_FLOAT32_C(   530.76) } },
      { SIMDE_FLOAT32_C(   296.66), SIMDE_FLOAT32_C(  -773.54), SIMDE_FLOAT32_C(   693.95), SIMDE_FLOAT32_C(   373.73),
        SIMDE_FLOAT32_C(    48.70), SIMDE_FLOAT32_C(   530.76) } },
    {
        { { SIMDE_FLOAT32_C(  -291.99), SIMDE_FLOAT32_C(  -805.30) },
          { SIMDE_FLOAT32_C(   641.71), SIMDE_FLOAT32_C(  -329.86) },
          { SIMDE_FLOAT32_C(   724.96), SIMDE_FLOAT32_C(  -488.11) } },
      { SIMDE_FLOAT32_C(  -291.99), SIMDE_FLOAT32_C(  -805.30), SIMDE_FLOAT32_C(   641.71), SIMDE_FLOAT32_C(  -329.86),
        SIMDE_FLOAT32_C(   724.96), SIMDE_FLOAT32_C(  -488.11) } },
    {
        { { SIMDE_FLOAT32_C(  -377.02), SIMDE_FLOAT32_C(  -795.66) },
          { SIMDE_FLOAT32_C(   760.72), SIMDE_FLOAT32_C(  -138.08) },
          { SIMDE_FLOAT32_C(  -784.23), SIMDE_FLOAT32_C(   930.17) } },
      { SIMDE_FLOAT32_C(  -377.02), SIMDE_FLOAT32_C(  -795.66), SIMDE_FLOAT32_C(   760.72), SIMDE_FLOAT32_C(  -138.08),
        SIMDE_FLOAT32_C(  -784.23), SIMDE_FLOAT32_C(   930.17) } },
    {
        { { SIMDE_FLOAT32_C(   510.43), SIMDE_FLOAT32_C(  -644.52) },
          { SIMDE_FLOAT32_C(   231.80), SIMDE_FLOAT32_C(   -21.82) },
          { SIMDE_FLOAT32_C(  -981.41), SIMDE_FLOAT32_C(  -195.60) } },
      { SIMDE_FLOAT32_C(   510.43), SIMDE_FLOAT32_C(  -644.52), SIMDE_FLOAT32_C(   231.80), SIMDE_FLOAT32_C(   -21.82),
        SIMDE_FLOAT32_C(  -981.41), SIMDE_FLOAT32_C(  -195.60) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x3_t r_ = { { simde_vld1_f32(test_vec[i].r[0]),
                                 simde_vld1_f32(test_vec[i].r[1]),
                                 simde_vld1_f32(test_vec[i].r[2]) } };

    simde_float32 a_[6];
    simde_vst1_f32_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t c = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_f32x2x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32 buf[6];
    simde_vst1_f32_x3(buf, d);

    simde_test_codegen_write_vf32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_f64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r[3][1];
    simde_float64 a[3];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(  -984.23) },
          { SIMDE_FLOAT64_C(    22.14) },
          { SIMDE_FLOAT64_C(  -393.70) } },
      { SIMDE_FLOAT64_C(  -984.23), SIMDE_FLOAT64_C(    22.14), SIMDE_FLOAT64_C(  -393.70) } },
    {
        { { SIMDE_FLOAT64_C(   186.03) },
          { SIMDE_FLOAT64_C(   884.75) },
          { SIMDE_FLOAT64_C(  -603.97) } },
      { SIMDE_FLOAT64_C(   186.03), SIMDE_FLOAT64_C(   884.75), SIMDE_FLOAT64_C(  -603.97) } },
    {
        { { SIMDE_FLOAT64_C(  -520.32) },
          { SIMDE_FLOAT64_C(   181.42) },
          { SIMDE_FLOAT64_C(  -377.51) } },
      { SIMDE_FLOAT64_C(  -520.32), SIMDE_FLOAT64_C(   181.42), SIMDE_FLOAT64_C(  -377.51) } },
    {
        { { SIMDE_FLOAT64_C(  -826.37) },
          { SIMDE_FLOAT64_C(  -444.85) },
          { SIMDE_FLOAT64_C(   671.18) } },
      { SIMDE_FLOAT64_C(  -826.37), SIMDE_FLOAT64_C(  -444.85), SIMDE_FLOAT64_C(   671.18) } },
    {
        { { SIMDE_FLOAT64_C(   704.39) },
          { SIMDE_FLOAT64_C(   263.16) },
          { SIMDE_FLOAT64_C(   865.89) } },
      { SIMDE_FLOAT64_C(   704.39), SIMDE_FLOAT64_C(   263.16), SIMDE_FLOAT64_C(   865.89) } },
    {
        { { SIMDE_FLOAT64_C(   346.10) },
          { SIMDE_FLOAT64_C(   933.30) },
          { SIMDE_FLOAT64_C(   590.84) } },
      { SIMDE_FLOAT64_C(   346.10), SIMDE_FLOAT64_C(   933.30), SIMDE_FLOAT64_C(   590.84) } },
    {
        { { SIMDE_FLOAT64_C(   857.99) },
          { SIMDE_FLOAT64_C(  -443.72) },
          { SIMDE_FLOAT64_C(   795.18) } },
      { SIMDE_FLOAT64_C(   857.99), SIMDE_FLOAT64_C(  -443.72), SIMDE_FLOAT64_C(   795.18) } },
    {
        { { SIMDE_FLOAT64_C(   618.71) },
          { SIMDE_FLOAT64_C(   418.20) },
          { SIMDE_FLOAT64_C(  -989.05) } },
      { SIMDE_FLOAT64_C(   618.71), SIMDE_FLOAT64_C(   418.20), SIMDE_FLOAT64_C(  -989.05) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x3_t r_ = { { simde_vld1_f64(test_vec[i].r[0]),
                                 simde_vld1_f64(test_vec[i].r[1]),
                                 simde_vld1_f64(test_vec[i].r[2]) } };

    simde_float64 a_[3];
    simde_vst1_f64_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t c = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_f64x1x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64 buf[3];
    simde_vst1_f64_x3(buf, d);

    simde_test_codegen_write_vf64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s8_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[3][8];
    int8_t a[24];
  } test_vec[] = {
    {
        { {  INT8_C(  89), -INT8_C(  93),  INT8_C( 125), -INT8_C(   4),  INT8_C(  26),  INT8_C(  11), -INT8_C(   4), -INT8_C(  78) },
          {  INT8_C(  83),  INT8_C(  54), -INT8_C(  19),  INT8_C(   5),  INT8_C(  77),  INT8_C(  63),  INT8_C( 112), -INT8_C(  68) },
          {  INT8_C(   7), -INT8_C(  57),      INT8_MAX, -INT8_C( 121), -INT8_C(  72),  INT8_C(  26),  INT8_C(   1), -INT8_C(  51) } },
      {  INT8_C(  89), -INT8_C(  93),  INT8_C( 125), -INT8_C(   4),  INT8_C(  26),  INT8_C(  11), -INT8_C(   4), -INT8_C(  78),
         INT8_C(  83),  INT8_C(  54), -INT8_C(  19),  INT8_C(   5),  INT8_C(  77),  INT8_C(  63),  INT8_C( 112), -INT8_C(  68),
         INT8_C(   7), -INT8_C(  57),      INT8_MAX, -INT8_C( 121), -INT8_C(  72),  INT8_C(  26),  INT8_C(   1), -INT8_C(  51) } },
    {
        { { -INT8_C(  23),  INT8_C(  41),  INT8_C(   1),  INT8_C(  29), -INT8_C(  97), -INT8_C(  79),  INT8_C( 100), -INT8_C(   8) },
          {  INT8_C(  84), -INT8_C(  31), -INT8_C(  11),  INT8_C( 110), -INT8_C(  20), -INT8_C(  15),  INT8_C(  33),  INT8_C(  63) },
          {  INT8_C(  39),  INT8_C(  14),  INT8_C(  68),  INT8_C( 116),  INT8_C(  77), -INT8_C(  76),  INT8_C(  49),  INT8_C(  85) } },
      { -INT8_C(  23),  INT8_C(  41),  INT8_C(   1),  INT8_C(  29), -INT8_C(  97), -INT8_C(  79),  INT8_C( 100), -INT8_C(   8),
         INT8_C(  84), -INT8_C(  31), -INT8_C(  11),  INT8_C( 110), -INT8_C(  20), -INT8_C(  15),  INT8_C(  33),  INT8_C(  63),
         INT8_C(  39),  INT8_C(  14),  INT8_C(  68),  INT8_C( 116),  INT8_C(  77), -INT8_C(  76),  INT8_C(  49),  INT8_C(  85) } },
    {
        { {  INT8_C( 124), -INT8_C(  80), -INT8_C(  36),  INT8_C(  52), -INT8_C(  54), -INT8_C(  35),  INT8_C(   1), -INT8_C(  77) },
          {  INT8_C(   6),  INT8_C(   3), -INT8_C(  48), -INT8_C(  91), -INT8_C(  76),  INT8_C(  52), -INT8_C(  98),  INT8_C(   8) },
          {  INT8_C(  21), -INT8_C( 109),  INT8_C( 119),  INT8_C(   1), -INT8_C( 124), -INT8_C( 104),  INT8_C(  65), -INT8_C(  84) } },
      {  INT8_C( 124), -INT8_C(  80), -INT8_C(  36),  INT8_C(  52), -INT8_C(  54), -INT8_C(  35),  INT8_C(   1), -INT8_C(  77),
         INT8_C(   6),  INT8_C(   3), -INT8_C(  48), -INT8_C(  91), -INT8_C(  76),  INT8_C(  52), -INT8_C(  98),  INT8_C(   8),
         INT8_C(  21), -INT8_C( 109),  INT8_C( 119),  INT8_C(   1), -INT8_C( 124), -INT8_C( 104),  INT8_C(  65), -INT8_C(  84) } },
    {
        { { -INT8_C(  90), -INT8_C( 123),  INT8_C(  32), -INT8_C(  13),  INT8_C(  58),  INT8_C(  81),  INT8_C(  72), -INT8_C(  74) },
          {  INT8_C(   1),  INT8_C(  36), -INT8_C(  22), -INT8_C(  53),  INT8_C(   1), -INT8_C(  20),      INT8_MAX,  INT8_C(   8) },
          { -INT8_C(  17),  INT8_C(  79), -INT8_C(  83), -INT8_C(  93), -INT8_C( 124),  INT8_C(  75), -INT8_C(  85), -INT8_C( 103) } },
      { -INT8_C(  90), -INT8_C( 123),  INT8_C(  32), -INT8_C(  13),  INT8_C(  58),  INT8_C(  81),  INT8_C(  72), -INT8_C(  74),
         INT8_C(   1),  INT8_C(  36), -INT8_C(  22), -INT8_C(  53),  INT8_C(   1), -INT8_C(  20),      INT8_MAX,  INT8_C(   8),
        -INT8_C(  17),  INT8_C(  79), -INT8_C(  83), -INT8_C(  93), -INT8_C( 124),  INT8_C(  75), -INT8_C(  85), -INT8_C( 103) } },
    {
        { { -INT8_C(  34),  INT8_C(  34), -INT8_C( 101),  INT8_C(  99), -INT8_C(  70), -INT8_C(  36),  INT8_C(  15),  INT8_C(  96) },
          {  INT8_C(  97),  INT8_C(  47),  INT8_C(  84), -INT8_C( 101), -INT8_C( 127), -INT8_C( 100),  INT8_C(  81), -INT8_C( 126) },
          { -INT8_C(  63),  INT8_C(  60),  INT8_C(  78), -INT8_C(  62),  INT8_C(  40), -INT8_C(  51), -INT8_C(  54),  INT8_C(  23) } },
      { -INT8_C(  34),  INT8_C(  34), -INT8_C( 101),  INT8_C(  99), -INT8_C(  70), -INT8_C(  36),  INT8_C(  15),  INT8_C(  96),
         INT8_C(  97),  INT8_C(  47),  INT8_C(  84), -INT8_C( 101), -INT8_C( 127), -INT8_C( 100),  INT8_C(  81), -INT8_C( 126),
        -INT8_C(  63),  INT8_C(  60),  INT8_C(  78), -INT8_C(  62),  INT8_C(  40), -INT8_C(  51), -INT8_C(  54),  INT8_C(  23) } },
    {
        { {  INT8_C(  28),  INT8_C( 120), -INT8_C(  70), -INT8_C(  96), -INT8_C(  61),  INT8_C( 101),  INT8_C(  58), -INT8_C(  94) },
          { -INT8_C( 120), -INT8_C(  43),  INT8_C(   5),  INT8_C(  66), -INT8_C(  79),  INT8_C(  20), -INT8_C(  93),  INT8_C(  18) },
          {  INT8_C(  67), -INT8_C(   9), -INT8_C(  82), -INT8_C(  60), -INT8_C( 109), -INT8_C(   1),  INT8_C(  71),  INT8_C(  84) } },
      {  INT8_C(  28),  INT8_C( 120), -INT8_C(  70), -INT8_C(  96), -INT8_C(  61),  INT8_C( 101),  INT8_C(  58), -INT8_C(  94),
        -INT8_C( 120), -INT8_C(  43),  INT8_C(   5),  INT8_C(  66), -INT8_C(  79),  INT8_C(  20), -INT8_C(  93),  INT8_C(  18),
         INT8_C(  67), -INT8_C(   9), -INT8_C(  82), -INT8_C(  60), -INT8_C( 109), -INT8_C(   1),  INT8_C(  71),  INT8_C(  84) } },
    {
        { {  INT8_C(  59), -INT8_C( 107),  INT8_C(  23),  INT8_C(  99),  INT8_C(  98), -INT8_C(  31),  INT8_C( 122),  INT8_C( 126) },
          {  INT8_C(  89),  INT8_C(  52),  INT8_C(  31),  INT8_C(  29), -INT8_C( 102),  INT8_C(  89), -INT8_C(  65),  INT8_C(  34) },
          {  INT8_C(  46), -INT8_C(  60),  INT8_C( 100), -INT8_C(  33), -INT8_C(  40),  INT8_C(   7), -INT8_C(  15),  INT8_C(  27) } },
      {  INT8_C(  59), -INT8_C( 107),  INT8_C(  23),  INT8_C(  99),  INT8_C(  98), -INT8_C(  31),  INT8_C( 122),  INT8_C( 126),
         INT8_C(  89),  INT8_C(  52),  INT8_C(  31),  INT8_C(  29), -INT8_C( 102),  INT8_C(  89), -INT8_C(  65),  INT8_C(  34),
         INT8_C(  46), -INT8_C(  60),  INT8_C( 100), -INT8_C(  33), -INT8_C(  40),  INT8_C(   7), -INT8_C(  15),  INT8_C(  27) } },
    {
        { { -INT8_C(   2), -INT8_C(  97), -INT8_C(  32), -INT8_C( 110), -INT8_C(  97),  INT8_C(  39), -INT8_C(  26), -INT8_C(  38) },
          { -INT8_C(  68), -INT8_C(   3),  INT8_C(  62),  INT8_C(  30), -INT8_C(  33), -INT8_C(  72), -INT8_C( 100),  INT8_C(  56) },
          { -INT8_C(  19), -INT8_C(  69),  INT8_C(  85), -INT8_C( 121),  INT8_C(  20),  INT8_C(  20), -INT8_C(  87),  INT8_C(  66) } },
      { -INT8_C(   2), -INT8_C(  97), -INT8_C(  32), -INT8_C( 110), -INT8_C(  97),  INT8_C(  39), -INT8_C(  26), -INT8_C(  38),
        -INT8_C(  68), -INT8_C(   3),  INT8_C(  62),  INT8_C(  30), -INT8_C(  33), -INT8_C(  72), -INT8_C( 100),  INT8_C(  56),
        -INT8_C(  19), -INT8_C(  69),  INT8_C(  85), -INT8_C( 121),  INT8_C(  20),  INT8_C(  20), -INT8_C(  87),  INT8_C(  66) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x3_t r_ = { { simde_vld1_s8(test_vec[i].r[0]),
                              simde_vld1_s8(test_vec[i].r[1]),
                              simde_vld1_s8(test_vec[i].r[2]) } };

    int8_t a_[24];
    simde_vst1_s8_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t c = simde_test_arm_neon_random_i8x8();
    simde_int8x8x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_i8x8x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    int8_t buf[24];
    simde_vst1_s8_x3(buf, d);

    simde_test_codegen_write_vi8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[3][4];
    int16_t a[12];
  } test_vec[] = {
    {
        { {  INT16_C(  3544), -INT16_C( 20447),  INT16_C(  4885),  INT16_C(  5068) },
          { -INT16_C( 21326),  INT16_C( 20901), -INT16_C( 29485), -INT16_C( 28884) },
          {  INT16_C( 27273),  INT16_C( 26797),  INT16_C( 18722),  INT16_C(  4001) } },
      {  INT16_C(  3544), -INT16_C( 20447),  INT16_C(  4885),  INT16_C(  5068), -INT16_C( 21326),  INT16_C( 20901), -INT16_C( 29485), -INT16_C( 28884),
         INT16_C( 27273),  INT16_C( 26797),  INT16_C( 18722),  INT16_C(  4001) } },
    {
        { { -INT16_C(  2555),  INT16_C(  6550),  INT16_C( 16139), -INT16_C(  7332) },
          {  INT16_C( 32077),  INT16_C( 25236),  INT16_C( 24720),  INT16_C( 17269) },
          {  INT16_C(  6924), -INT16_C(  8300), -INT16_C( 16217),  INT16_C( 12398) } },
      { -INT16_C(  2555),  INT16_C(  6550),  INT16_C( 16139), -INT16_C(  7332),  INT16_C( 32077),  INT16_C( 25236),  INT16_C( 24720),  INT16_C( 17269),
         INT16_C(  6924), -INT16_C(  8300), -INT16_C( 16217),  INT16_C( 12398) } },
    {
        { {  INT16_C(  6954),  INT16_C( 19865),  INT16_C( 14948),  INT16_C( 26972) },
          { -INT16_C(  3280),  INT16_C( 15235), -INT16_C(  8398),  INT16_C( 32543) },
          { -INT16_C( 19620), -INT16_C(  4639),  INT16_C( 22291),  INT16_C(  7984) } },
      {  INT16_C(  6954),  INT16_C( 19865),  INT16_C( 14948),  INT16_C( 26972), -INT16_C(  3280),  INT16_C( 15235), -INT16_C(  8398),  INT16_C( 32543),
        -INT16_C( 19620), -INT16_C(  4639),  INT16_C( 22291),  INT16_C(  7984) } },
    {
        { { -INT16_C( 15246),  INT16_C(  6654),  INT16_C( 27781), -INT16_C( 20663) },
          { -INT16_C(  7545), -INT16_C(  5124),  INT16_C( 22812),  INT16_C( 19797) },
          { -INT16_C( 10164),  INT16_C( 32392), -INT16_C( 22601),  INT16_C(  5118) } },
      { -INT16_C( 15246),  INT16_C(  6654),  INT16_C( 27781), -INT16_C( 20663), -INT16_C(  7545), -INT16_C(  5124),  INT16_C( 22812),  INT16_C( 19797),
        -INT16_C( 10164),  INT16_C( 32392), -INT16_C( 22601),  INT16_C(  5118) } },
    {
        { { -INT16_C(  8358),  INT16_C( 27904),  INT16_C( 12342), -INT16_C( 22388) },
          { -INT16_C( 29963),  INT16_C( 31425),  INT16_C(  3062),  INT16_C( 32041) },
          {  INT16_C(  9965),  INT16_C(  2665), -INT16_C( 16769), -INT16_C( 13481) } },
      { -INT16_C(  8358),  INT16_C( 27904),  INT16_C( 12342), -INT16_C( 22388), -INT16_C( 29963),  INT16_C( 31425),  INT16_C(  3062),  INT16_C( 32041),
         INT16_C(  9965),  INT16_C(  2665), -INT16_C( 16769), -INT16_C( 13481) } },
    {
        { { -INT16_C(  8298),  INT16_C( 19785),  INT16_C( 18311), -INT16_C(  7840) },
          {  INT16_C( 24871),  INT16_C( 23887), -INT16_C(  9327), -INT16_C( 31226) },
          { -INT16_C( 14490),  INT16_C( 23552),  INT16_C( 10962), -INT16_C( 16166) } },
      { -INT16_C(  8298),  INT16_C( 19785),  INT16_C( 18311), -INT16_C(  7840),  INT16_C( 24871),  INT16_C( 23887), -INT16_C(  9327), -INT16_C( 31226),
        -INT16_C( 14490),  INT16_C( 23552),  INT16_C( 10962), -INT16_C( 16166) } },
    {
        { {  INT16_C( 17232), -INT16_C( 12342),  INT16_C(  8449), -INT16_C( 26726) },
          { -INT16_C(  7424), -INT16_C( 30748),  INT16_C( 17451),  INT16_C( 21097) },
          { -INT16_C( 18267),  INT16_C( 14255), -INT16_C( 19053), -INT16_C(  1603) } },
      {  INT16_C( 17232), -INT16_C( 12342),  INT16_C(  8449), -INT16_C( 26726), -INT16_C(  7424), -INT16_C( 30748),  INT16_C( 17451),  INT16_C( 21097),
        -INT16_C( 18267),  INT16_C( 14255), -INT16_C( 19053), -INT16_C(  1603) } },
    {
        { { -INT16_C( 16771),  INT16_C( 20310),  INT16_C( 12520),  INT16_C( 14351) },
          { -INT16_C(  9869),  INT16_C( 29703), -INT16_C( 24070), -INT16_C(  1269) },
          { -INT16_C(  4220), -INT16_C( 20606), -INT16_C(  5325), -INT16_C(  9983) } },
      { -INT16_C( 16771),  INT16_C( 20310),  INT16_C( 12520),  INT16_C( 14351), -INT16_C(  9869),  INT16_C( 29703), -INT16_C( 24070), -INT16_C(  1269),
        -INT16_C(  4220), -INT16_C( 20606), -INT16_C(  5325), -INT16_C(  9983) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x3_t r_ = { { simde_vld1_s16(test_vec[i].r[0]),
                               simde_vld1_s16(test_vec[i].r[1]),
                               simde_vld1_s16(test_vec[i].r[2]) } };

    int16_t a_[12];
    simde_vst1_s16_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t c = simde_test_arm_neon_random_i16x4();
    simde_int16x4x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_i16x4x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    int16_t buf[12];
    simde_vst1_s16_x3(buf, d);

    simde_test_codegen_write_vi16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[3][2];
    int32_t a[6];
  } test_vec[] = {
    {
        { {  INT32_C(   923840931), -INT32_C(   483340954) },
          {  INT32_C(  1932756619),  INT32_C(   699089590) },
          {  INT32_C(   379433500), -INT32_C(   669931437) } },
      {  INT32_C(   923840931), -INT32_C(   483340954),  INT32_C(  1932756619),  INT32_C(   699089590),  INT32_C(   379433500), -INT32_C(   669931437) } },
    {
        { { -INT32_C(   880307049),  INT32_C(   597985663) },
          { -INT32_C(  1604668358),  INT32_C(   226790017) },
          { -INT32_C(   947865839),  INT32_C(   368127225) } },
      { -INT32_C(   880307049),  INT32_C(   597985663), -INT32_C(  1604668358),  INT32_C(   226790017), -INT32_C(   947865839),  INT32_C(   368127225) } },
    {
        { {  INT32_C(   841780958), -INT32_C(   838189769) },
          {  INT32_C(  1369018833),  INT32_C(  1416903962) },
          {  INT32_C(  1945489137),  INT32_C(  1770027352) } },
      {  INT32_C(   841780958), -INT32_C(   838189769),  INT32_C(  1369018833),  INT32_C(  1416903962),  INT32_C(  1945489137),  INT32_C(  1770027352) } },
    {
        { {  INT32_C(   691077168),  INT32_C(   188686892) },
          { -INT32_C(   415405136),  INT32_C(  2058766248) },
          { -INT32_C(   204779560),  INT32_C(  2118598541) } },
      {  INT32_C(   691077168),  INT32_C(   188686892), -INT32_C(   415405136),  INT32_C(  2058766248), -INT32_C(   204779560),  INT32_C(  2118598541) } },
    {
        { {  INT32_C(  1710308365), -INT32_C(   439389771) },
          { -INT32_C(  1643184014), -INT32_C(   760656350) },
          {  INT32_C(  1639638713),  INT32_C(   115044397) } },
      {  INT32_C(  1710308365), -INT32_C(   439389771), -INT32_C(  1643184014), -INT32_C(   760656350),  INT32_C(  1639638713),  INT32_C(   115044397) } },
    {
        { {  INT32_C(  1291429567), -INT32_C(   221560603) },
          {  INT32_C(   844676221), -INT32_C(  1609029842) },
          {  INT32_C(  1228810023),  INT32_C(   773580917) } },
      {  INT32_C(  1291429567), -INT32_C(   221560603),  INT32_C(   844676221), -INT32_C(  1609029842),  INT32_C(  1228810023),  INT32_C(   773580917) } },
    {
        { { -INT32_C(    57682482),  INT32_C(    84044613) },
          { -INT32_C(   145622255), -INT32_C(  1192682437) },
          {  INT32_C(   132858329), -INT32_C(  1884880024) } },
      { -INT32_C(    57682482),  INT32_C(    84044613), -INT32_C(   145622255), -INT32_C(  1192682437),  INT32_C(   132858329), -INT32_C(  1884880024) } },
    {
        { { -INT32_C(  1613175510), -INT32_C(  1664224051) },
          {  INT32_C(   261643465), -INT32_C(   652961081) },
          { -INT32_C(   791648875),  INT32_C(  1535752578) } },
      { -INT32_C(  1613175510), -INT32_C(  1664224051),  INT32_C(   261643465), -INT32_C(   652961081), -INT32_C(   791648875),  INT32_C(  1535752578) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x3_t r_ = { { simde_vld1_s32(test_vec[i].r[0]),
                               simde_vld1_s32(test_vec[i].r[1]),
                               simde_vld1_s32(test_vec[i].r[2]) } };

    int32_t a_[6];
    simde_vst1_s32_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t c = simde_test_arm_neon_random_i32x2();
    simde_int32x2x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_i32x2x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    int32_t buf[6];
    simde_vst1_s32_x3(buf, d);

    simde_test_codegen_write_vi32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r[3][1];
    int64_t a[3];
  } test_vec[] = {
    {
        { { -INT64_C( 6777062605889309445) },
          { -INT64_C( 8550068775414608914) },
          {  INT64_C( 2236789874480443497) } },
      { -INT64_C( 6777062605889309445), -INT64_C( 8550068775414608914),  INT64_C( 2236789874480443497) } },
    {
        { { -INT64_C( 8147442100629153263) },
          {  INT64_C( 5189524842729328876) },
          { -INT64_C( 4901785214574639952) } },
      { -INT64_C( 8147442100629153263),  INT64_C( 5189524842729328876), -INT64_C( 4901785214574639952) } },
    {
        { {  INT64_C( 5689724449711755596) },
          {  INT64_C( 5328550408659068112) },
          {  INT64_C( 8773770502975906849) } },
      {  INT64_C( 5689724449711755596),  INT64_C( 5328550408659068112),  INT64_C( 8773770502975906849) } },
    {
        { {  INT64_C( 7927146930988762870) },
          { -INT64_C( 5404537373448671629) },
          { -INT64_C( 3259468472918679266) } },
      {  INT64_C( 7927146930988762870), -INT64_C( 5404537373448671629), -INT64_C( 3259468472918679266) } },
    {
        { {  INT64_C( 1814967295903887854) },
          {  INT64_C( 8099552392999082710) },
          {  INT64_C(  282072995980159825) } },
      {  INT64_C( 1814967295903887854),  INT64_C( 8099552392999082710),  INT64_C(  282072995980159825) } },
    {
        { { -INT64_C(  395118245000117760) },
          { -INT64_C( 5192400910743907916) },
          {  INT64_C(  389586329994744060) } },
      { -INT64_C(  395118245000117760), -INT64_C( 5192400910743907916),  INT64_C(  389586329994744060) } },
    {
        { { -INT64_C( 6221118528968488510) },
          {  INT64_C( 2175202792281155624) },
          { -INT64_C( 4735000909351362383) } },
      { -INT64_C( 6221118528968488510),  INT64_C( 2175202792281155624), -INT64_C( 4735000909351362383) } },
    {
        { { -INT64_C( 3319681722119358410) },
          {  INT64_C( 8645260158755678632) },
          { -INT64_C( 1885923899033823926) } },
      { -INT64_C( 3319681722119358410),  INT64_C( 8645260158755678632), -INT64_C( 1885923899033823926) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x3_t r_ = { { simde_vld1_s64(test_vec[i].r[0]),
                               simde_vld1_s64(test_vec[i].r[1]),
                               simde_vld1_s64(test_vec[i].r[2]) } };

    int64_t a_[3];
    simde_vst1_s64_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t c = simde_test_arm_neon_random_i64x1();
    simde_int64x1x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_i64x1x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    int64_t buf[3];
    simde_vst1_s64_x3(buf, d);

    simde_test_codegen_write_vi64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u8_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[3][8];
    uint8_t a[24];
  } test_vec[] = {
    {
        { { UINT8_C(187), UINT8_C(200), UINT8_C(119), UINT8_C(125), UINT8_C(174), UINT8_C(192), UINT8_C( 60), UINT8_C(228) },
          { UINT8_C(185), UINT8_C(243), UINT8_C(205), UINT8_C(200), UINT8_C( 18), UINT8_C(188), UINT8_C(153), UINT8_C(187) },
          { UINT8_C(229), UINT8_C( 17), UINT8_C( 12), UINT8_C( 52), UINT8_C( 51), UINT8_C(  6), UINT8_C(171), UINT8_C(125) } },
      { UINT8_C(187), UINT8_C(200), UINT8_C(119), UINT8_C(125), UINT8_C(174), UINT8_C(192), UINT8_C( 60), UINT8_C(228),
        UINT8_C(185), UINT8_C(243), UINT8_C(205), UINT8_C(200), UINT8_C( 18), UINT8_C(188), UINT8_C(153), UINT8_C(187),
        UINT8_C(229), UINT8_C( 17), UINT8_C( 12), UINT8_C( 52), UINT8_C( 51), UINT8_C(  6), UINT8_C(171), UINT8_C(125) } },
    {
        { { UINT8_C( 91), UINT8_C( 87), UINT8_C( 49), UINT8_C(143), UINT8_C( 49), UINT8_C(  4), UINT8_C(117), UINT8_C(236) },
          { UINT8_C(205), UINT8_C(236), UINT8_C(106), UINT8_C(123), UINT8_C(173), UINT8_C(166), UINT8_C( 95), UINT8_C(102) },
          { UINT8_C(153), UINT8_C( 44), UINT8_C( 46), UINT8_C(171), UINT8_C(232), UINT8_C(199), UINT8_C(102), UINT8_C(206) } },
      { UINT8_C( 91), UINT8_C( 87), UINT8_C( 49), UINT8_C(143), UINT8_C( 49), UINT8_C(  4), UINT8_C(117), UINT8_C(236),
        UINT8_C(205), UINT8_C(236), UINT8_C(106), UINT8_C(123), UINT8_C(173), UINT8_C(166), UINT8_C( 95), UINT8_C(102),
        UINT8_C(153), UINT8_C( 44), UINT8_C( 46), UINT8_C(171), UINT8_C(232), UINT8_C(199), UINT8_C(102), UINT8_C(206) } },
    {
        { { UINT8_C(216), UINT8_C(114), UINT8_C(  2), UINT8_C( 11), UINT8_C(120), UINT8_C(174), UINT8_C(136), UINT8_C(211) },
          { UINT8_C(  5), UINT8_C(185), UINT8_C( 99), UINT8_C( 54), UINT8_C(190), UINT8_C(216), UINT8_C( 35), UINT8_C(139) },
          { UINT8_C(196), UINT8_C(141), UINT8_C(  6), UINT8_C(113), UINT8_C( 51), UINT8_C(101), UINT8_C(215), UINT8_C(204) } },
      { UINT8_C(216), UINT8_C(114), UINT8_C(  2), UINT8_C( 11), UINT8_C(120), UINT8_C(174), UINT8_C(136), UINT8_C(211),
        UINT8_C(  5), UINT8_C(185), UINT8_C( 99), UINT8_C( 54), UINT8_C(190), UINT8_C(216), UINT8_C( 35), UINT8_C(139),
        UINT8_C(196), UINT8_C(141), UINT8_C(  6), UINT8_C(113), UINT8_C( 51), UINT8_C(101), UINT8_C(215), UINT8_C(204) } },
    {
        { { UINT8_C(145), UINT8_C(  5), UINT8_C(119), UINT8_C(122), UINT8_C(204), UINT8_C(222), UINT8_C( 72), UINT8_C(164) },
          { UINT8_C( 80), UINT8_C( 74), UINT8_C(175), UINT8_C(201), UINT8_C(248), UINT8_C( 55), UINT8_C(156), UINT8_C(253) },
          { UINT8_C(241),    UINT8_MAX, UINT8_C( 52), UINT8_C(175), UINT8_C(215), UINT8_C( 87), UINT8_C( 58), UINT8_C(156) } },
      { UINT8_C(145), UINT8_C(  5), UINT8_C(119), UINT8_C(122), UINT8_C(204), UINT8_C(222), UINT8_C( 72), UINT8_C(164),
        UINT8_C( 80), UINT8_C( 74), UINT8_C(175), UINT8_C(201), UINT8_C(248), UINT8_C( 55), UINT8_C(156), UINT8_C(253),
        UINT8_C(241),    UINT8_MAX, UINT8_C( 52), UINT8_C(175), UINT8_C(215), UINT8_C( 87), UINT8_C( 58), UINT8_C(156) } },
    {
        { { UINT8_C(228), UINT8_C( 64), UINT8_C( 13), UINT8_C( 23), UINT8_C(165), UINT8_C(229), UINT8_C(227), UINT8_C( 54) },
          { UINT8_C(234), UINT8_C( 90), UINT8_C(176), UINT8_C(183), UINT8_C( 56), UINT8_C(248), UINT8_C( 91), UINT8_C(137) },
          { UINT8_C( 67), UINT8_C( 11), UINT8_C( 82), UINT8_C( 59), UINT8_C( 66), UINT8_C(238), UINT8_C( 57), UINT8_C( 51) } },
      { UINT8_C(228), UINT8_C( 64), UINT8_C( 13), UINT8_C( 23), UINT8_C(165), UINT8_C(229), UINT8_C(227), UINT8_C( 54),
        UINT8_C(234), UINT8_C( 90), UINT8_C(176), UINT8_C(183), UINT8_C( 56), UINT8_C(248), UINT8_C( 91), UINT8_C(137),
        UINT8_C( 67), UINT8_C( 11), UINT8_C( 82), UINT8_C( 59), UINT8_C( 66), UINT8_C(238), UINT8_C( 57), UINT8_C( 51) } },
    {
        { { UINT8_C(238), UINT8_C(109), UINT8_C(226), UINT8_C(197), UINT8_C(196), UINT8_C( 28), UINT8_C( 97), UINT8_C(168) },
          { UINT8_C( 92), UINT8_C(111), UINT8_C(191), UINT8_C(  1), UINT8_C( 84), UINT8_C(162), UINT8_C( 56), UINT8_C( 62) },
          { UINT8_C(252), UINT8_C(232), UINT8_C(245), UINT8_C( 53), UINT8_C(225), UINT8_C( 81), UINT8_C(190), UINT8_C( 36) } },
      { UINT8_C(238), UINT8_C(109), UINT8_C(226), UINT8_C(197), UINT8_C(196), UINT8_C( 28), UINT8_C( 97), UINT8_C(168),
        UINT8_C( 92), UINT8_C(111), UINT8_C(191), UINT8_C(  1), UINT8_C( 84), UINT8_C(162), UINT8_C( 56), UINT8_C( 62),
        UINT8_C(252), UINT8_C(232), UINT8_C(245), UINT8_C( 53), UINT8_C(225), UINT8_C( 81), UINT8_C(190), UINT8_C( 36) } },
    {
        { { UINT8_C( 92), UINT8_C( 16), UINT8_C( 95), UINT8_C(158), UINT8_C(254), UINT8_C(152), UINT8_C(210), UINT8_C(236) },
          { UINT8_C(  5), UINT8_C(180), UINT8_C(178), UINT8_C(201), UINT8_C(209), UINT8_C( 19), UINT8_C(113), UINT8_C( 45) },
          { UINT8_C(130), UINT8_C( 48), UINT8_C( 47), UINT8_C(214), UINT8_C(210), UINT8_C(103), UINT8_C( 21), UINT8_C(207) } },
      { UINT8_C( 92), UINT8_C( 16), UINT8_C( 95), UINT8_C(158), UINT8_C(254), UINT8_C(152), UINT8_C(210), UINT8_C(236),
        UINT8_C(  5), UINT8_C(180), UINT8_C(178), UINT8_C(201), UINT8_C(209), UINT8_C( 19), UINT8_C(113), UINT8_C( 45),
        UINT8_C(130), UINT8_C( 48), UINT8_C( 47), UINT8_C(214), UINT8_C(210), UINT8_C(103), UINT8_C( 21), UINT8_C(207) } },
    {
        { { UINT8_C( 79), UINT8_C( 10), UINT8_C(  4), UINT8_C( 48), UINT8_C( 91), UINT8_C(194), UINT8_C( 84), UINT8_C(183) },
          { UINT8_C(210), UINT8_C(180), UINT8_C( 86), UINT8_C(208), UINT8_C( 76), UINT8_C( 40), UINT8_C(189), UINT8_C( 82) },
          { UINT8_C(220), UINT8_C(111), UINT8_C( 27), UINT8_C(173), UINT8_C(130), UINT8_C(141), UINT8_C(219), UINT8_C(  5) } },
      { UINT8_C( 79), UINT8_C( 10), UINT8_C(  4), UINT8_C( 48), UINT8_C( 91), UINT8_C(194), UINT8_C( 84), UINT8_C(183),
        UINT8_C(210), UINT8_C(180), UINT8_C( 86), UINT8_C(208), UINT8_C( 76), UINT8_C( 40), UINT8_C(189), UINT8_C( 82),
        UINT8_C(220), UINT8_C(111), UINT8_C( 27), UINT8_C(173), UINT8_C(130), UINT8_C(141), UINT8_C(219), UINT8_C(  5) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x3_t r_ = { { simde_vld1_u8(test_vec[i].r[0]),
                               simde_vld1_u8(test_vec[i].r[1]),
                               simde_vld1_u8(test_vec[i].r[2]) } };

    uint8_t a_[24];
    simde_vst1_u8_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t c = simde_test_arm_neon_random_u8x8();
    simde_uint8x8x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_u8x8x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    uint8_t buf[24];
    simde_vst1_u8_x3(buf, d);

    simde_test_codegen_write_vu8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u16_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[3][4];
    uint16_t a[12];
  } test_vec[] = {
    {
        { { UINT16_C( 2749), UINT16_C(37083), UINT16_C(61553), UINT16_C(49247) },
          { UINT16_C(25595), UINT16_C(22257), UINT16_C(17701), UINT16_C(63246) },
          { UINT16_C(25849), UINT16_C(18119), UINT16_C(33932), UINT16_C(26776) } },
      { UINT16_C( 2749), UINT16_C(37083), UINT16_C(61553), UINT16_C(49247), UINT16_C(25595), UINT16_C(22257), UINT16_C(17701), UINT16_C(63246),
        UINT16_C(25849), UINT16_C(18119), UINT16_C(33932), UINT16_C(26776) } },
    {
        { { UINT16_C(46067), UINT16_C(30230), UINT16_C(61760), UINT16_C(65147) },
          { UINT16_C(22267), UINT16_C(27790), UINT16_C(60743), UINT16_C(16940) },
          { UINT16_C( 7504), UINT16_C(30104), UINT16_C(42595), UINT16_C(23660) } },
      { UINT16_C(46067), UINT16_C(30230), UINT16_C(61760), UINT16_C(65147), UINT16_C(22267), UINT16_C(27790), UINT16_C(60743), UINT16_C(16940),
        UINT16_C( 7504), UINT16_C(30104), UINT16_C(42595), UINT16_C(23660) } },
    {
        { { UINT16_C(13066), UINT16_C(38562), UINT16_C(15032), UINT16_C(44031) },
          { UINT16_C( 5614), UINT16_C(11809), UINT16_C(39942), UINT16_C(  300) },
          { UINT16_C(47859), UINT16_C(14957), UINT16_C(39335), UINT16_C(63356) } },
      { UINT16_C(13066), UINT16_C(38562), UINT16_C(15032), UINT16_C(44031), UINT16_C( 5614), UINT16_C(11809), UINT16_C(39942), UINT16_C(  300),
        UINT16_C(47859), UINT16_C(14957), UINT16_C(39335), UINT16_C(63356) } },
    {
        { { UINT16_C( 5303), UINT16_C( 6764), UINT16_C(55483), UINT16_C(50550) },
          { UINT16_C( 6412), UINT16_C(50268), UINT16_C(23379), UINT16_C(16751) },
          { UINT16_C(37232), UINT16_C(30320), UINT16_C(39981), UINT16_C( 8311) } },
      { UINT16_C( 5303), UINT16_C( 6764), UINT16_C(55483), UINT16_C(50550), UINT16_C( 6412), UINT16_C(50268), UINT16_C(23379), UINT16_C(16751),
        UINT16_C(37232), UINT16_C(30320), UINT16_C(39981), UINT16_C( 8311) } },
    {
        { { UINT16_C(58455), UINT16_C(65114), UINT16_C(54909), UINT16_C(13558) },
          { UINT16_C(25323), UINT16_C(42574), UINT16_C(50491), UINT16_C(18283) },
          { UINT16_C(51166), UINT16_C(12555), UINT16_C(31266), UINT16_C(37491) } },
      { UINT16_C(58455), UINT16_C(65114), UINT16_C(54909), UINT16_C(13558), UINT16_C(25323), UINT16_C(42574), UINT16_C(50491), UINT16_C(18283),
        UINT16_C(51166), UINT16_C(12555), UINT16_C(31266), UINT16_C(37491) } },
    {
        { { UINT16_C(58123), UINT16_C(14600), UINT16_C(32639), UINT16_C(54873) },
          { UINT16_C(46179), UINT16_C(57813), UINT16_C(52106), UINT16_C(29973) },
          { UINT16_C(25645), UINT16_C(26651), UINT16_C(34601), UINT16_C( 1967) } },
      { UINT16_C(58123), UINT16_C(14600), UINT16_C(32639), UINT16_C(54873), UINT16_C(46179), UINT16_C(57813), UINT16_C(52106), UINT16_C(29973),
        UINT16_C(25645), UINT16_C(26651), UINT16_C(34601), UINT16_C( 1967) } },
    {
        { { UINT16_C(47694), UINT16_C(28984), UINT16_C(43829), UINT16_C(16387) },
          { UINT16_C( 3214), UINT16_C( 3705), UINT16_C(54155), UINT16_C(61412) },
          { UINT16_C(47495), UINT16_C( 4560), UINT16_C(58756), UINT16_C(45703) } },
      { UINT16_C(47694), UINT16_C(28984), UINT16_C(43829), UINT16_C(16387), UINT16_C( 3214), UINT16_C( 3705), UINT16_C(54155), UINT16_C(61412),
        UINT16_C(47495), UINT16_C( 4560), UINT16_C(58756), UINT16_C(45703) } },
    {
        { { UINT16_C(41545), UINT16_C(29210), UINT16_C(51753), UINT16_C(30841) },
          { UINT16_C(45700), UINT16_C(47593), UINT16_C(60509), UINT16_C(60666) },
          { UINT16_C(29688), UINT16_C(34042), UINT16_C(56902), UINT16_C(52595) } },
      { UINT16_C(41545), UINT16_C(29210), UINT16_C(51753), UINT16_C(30841), UINT16_C(45700), UINT16_C(47593), UINT16_C(60509), UINT16_C(60666),
        UINT16_C(29688), UINT16_C(34042), UINT16_C(56902), UINT16_C(52595) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x3_t r_ = { { simde_vld1_u16(test_vec[i].r[0]),
                                simde_vld1_u16(test_vec[i].r[1]),
                                simde_vld1_u16(test_vec[i].r[2]) } };

    uint16_t a_[12];
    simde_vst1_u16_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t c = simde_test_arm_neon_random_u16x4();
    simde_uint16x4x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_u16x4x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    uint16_t buf[12];
    simde_vst1_u16_x3(buf, d);

    simde_test_codegen_write_vu16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u32_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[3][2];
    uint32_t a[6];
  } test_vec[] = {
   {
        { { UINT32_C( 484393880), UINT32_C(1926129192) },
          { UINT32_C( 853862664), UINT32_C( 933912243) },
          { UINT32_C(1844548368), UINT32_C(2019158911) } },
      { UINT32_C( 484393880), UINT32_C(1926129192), UINT32_C( 853862664), UINT32_C( 933912243), UINT32_C(1844548368), UINT32_C(2019158911) } },
    {
        { { UINT32_C(2784777054), UINT32_C(3396497202) },
          { UINT32_C(3672527282), UINT32_C(3226252727) },
          { UINT32_C(1374826910), UINT32_C(2676530319) } },
      { UINT32_C(2784777054), UINT32_C(3396497202), UINT32_C(3672527282), UINT32_C(3226252727), UINT32_C(1374826910), UINT32_C(2676530319) } },
    {
        { { UINT32_C(2920053039), UINT32_C(3274073700) },
          { UINT32_C(3949470393), UINT32_C(1135991441) },
          { UINT32_C(3810434092), UINT32_C(4020464209) } },
      { UINT32_C(2920053039), UINT32_C(3274073700), UINT32_C(3949470393), UINT32_C(1135991441), UINT32_C(3810434092), UINT32_C(4020464209) } },
    {
        { { UINT32_C( 708875675), UINT32_C(1623836721) },
          { UINT32_C(2786055746), UINT32_C(4117312828) },
          { UINT32_C(3923890520), UINT32_C(3626866348) } },
      { UINT32_C( 708875675), UINT32_C(1623836721), UINT32_C(2786055746), UINT32_C(4117312828), UINT32_C(3923890520), UINT32_C(3626866348) } },
    {
        { { UINT32_C(2210089778), UINT32_C(1366450101) },
          { UINT32_C( 645640948), UINT32_C(3179693435) },
          { UINT32_C(1466144027), UINT32_C( 592235979) } },
      { UINT32_C(2210089778), UINT32_C(1366450101), UINT32_C( 645640948), UINT32_C(3179693435), UINT32_C(1466144027), UINT32_C( 592235979) } },
    {
        { { UINT32_C(1242312094), UINT32_C(4129438148) },
          { UINT32_C( 981130884), UINT32_C( 831253565) },
          { UINT32_C( 441910943), UINT32_C(1725423179) } },
      { UINT32_C(1242312094), UINT32_C(4129438148), UINT32_C( 981130884), UINT32_C( 831253565), UINT32_C( 441910943), UINT32_C(1725423179) } },
    {
        { { UINT32_C(1052588659), UINT32_C(2791377415) },
          { UINT32_C(4226838071), UINT32_C( 754062247) },
          { UINT32_C( 778464497), UINT32_C(4150260056) } },
      { UINT32_C(1052588659), UINT32_C(2791377415), UINT32_C(4226838071), UINT32_C( 754062247), UINT32_C( 778464497), UINT32_C(4150260056) } },
    {
        { { UINT32_C(1125234679), UINT32_C( 145352853) },
          { UINT32_C( 709322531), UINT32_C(2832246897) },
          { UINT32_C(3198468374), UINT32_C(3320485588) } },
      { UINT32_C(1125234679), UINT32_C( 145352853), UINT32_C( 709322531), UINT32_C(2832246897), UINT32_C(3198468374), UINT32_C(3320485588) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x3_t r_ = { { simde_vld1_u32(test_vec[i].r[0]),
                                simde_vld1_u32(test_vec[i].r[1]),
                                simde_vld1_u32(test_vec[i].r[2]) } };

    uint32_t a_[6];
    simde_vst1_u32_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t c = simde_test_arm_neon_random_u32x2();
    simde_uint32x2x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_u32x2x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    uint32_t buf[6];
    simde_vst1_u32_x3(buf, d);

    simde_test_codegen_write_vu32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u64_x3 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r[3][1];
    uint64_t a[3];
  } test_vec[] = {
    {
        { { UINT64_C( 4058396654866485250) },
          { UINT64_C( 8045440270327309065) },
          { UINT64_C(12512524336451153548) } },
      { UINT64_C( 4058396654866485250), UINT64_C( 8045440270327309065), UINT64_C(12512524336451153548) } },
    {
        { { UINT64_C(16268222174520363307) },
          { UINT64_C( 1377694709190539173) },
          { UINT64_C( 5452830827235875569) } },
      { UINT64_C(16268222174520363307), UINT64_C( 1377694709190539173), UINT64_C( 5452830827235875569) } },
    {
        { { UINT64_C(15819717984974816838) },
          { UINT64_C(17291744810337236279) },
          { UINT64_C(12930384021297640533) } },
      { UINT64_C(15819717984974816838), UINT64_C(17291744810337236279), UINT64_C(12930384021297640533) } },
    {
        { { UINT64_C(14021849117738738573) },
          { UINT64_C(  319238586511646691) },
          { UINT64_C( 4275907152009906206) } },
      { UINT64_C(14021849117738738573), UINT64_C(  319238586511646691), UINT64_C( 4275907152009906206) } },
    {
        { { UINT64_C(12518893292099349574) },
          { UINT64_C( 3345208373111532846) },
          { UINT64_C( 5927071585528777584) } },
      { UINT64_C(12518893292099349574), UINT64_C( 3345208373111532846), UINT64_C( 5927071585528777584) } },
    {
        { { UINT64_C(13085790833028521080) },
          { UINT64_C( 7929001936303240253) },
          { UINT64_C(  333130670536131366) } },
      { UINT64_C(13085790833028521080), UINT64_C( 7929001936303240253), UINT64_C(  333130670536131366) } },
    {
        { { UINT64_C(  654573978626711695) },
          { UINT64_C( 2090517814441463775) },
          { UINT64_C( 6982131084443697207) } },
      { UINT64_C(  654573978626711695), UINT64_C( 2090517814441463775), UINT64_C( 6982131084443697207) } },
    {
        { { UINT64_C( 1305886121058762374) },
          { UINT64_C(14153384145091650001) },
          { UINT64_C(  916506531343815354) } },
      { UINT64_C( 1305886121058762374), UINT64_C(14153384145091650001), UINT64_C(  916506531343815354) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x3_t r_ = { { simde_vld1_u64(test_vec[i].r[0]),
                                simde_vld1_u64(test_vec[i].r[1]),
                                simde_vld1_u64(test_vec[i].r[2]) } };

    uint64_t a_[3];
    simde_vst1_u64_x3(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t c = simde_test_arm_neon_random_u64x1();
    simde_uint64x1x3_t d = {{a, b, c}};

    simde_test_arm_neon_write_u64x1x3(2, d, SIMDE_TEST_VEC_POS_FIRST);

    uint64_t buf[3];
    simde_vst1_u64_x3(buf, d);

    simde_test_codegen_write_vu64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s64_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u8_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u16_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u32_x3)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u64_x3)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
