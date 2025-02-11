
#include "test/test.h"
#define SIMDE_TEST_ARM_NEON_INSN st1q_x4
#include "test-neon.h"
#include "../../../simde/arm/neon/st1q_x4.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst1q_f32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r[4][4];
    simde_float32 a[16];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(   415.30), SIMDE_FLOAT32_C(  -128.97), SIMDE_FLOAT32_C(  -764.36), SIMDE_FLOAT32_C(   567.37) },
          { SIMDE_FLOAT32_C(  -242.35), SIMDE_FLOAT32_C(  -382.14), SIMDE_FLOAT32_C(  -602.24), SIMDE_FLOAT32_C(   885.83) },
          { SIMDE_FLOAT32_C(   450.10), SIMDE_FLOAT32_C(  -580.76), SIMDE_FLOAT32_C(   -43.35), SIMDE_FLOAT32_C(  -176.72) },
          { SIMDE_FLOAT32_C(   697.79), SIMDE_FLOAT32_C(  -514.98), SIMDE_FLOAT32_C(  -539.79), SIMDE_FLOAT32_C(    81.80) } },
      { SIMDE_FLOAT32_C(   415.30), SIMDE_FLOAT32_C(  -128.97), SIMDE_FLOAT32_C(  -764.36), SIMDE_FLOAT32_C(   567.37),
        SIMDE_FLOAT32_C(  -242.35), SIMDE_FLOAT32_C(  -382.14), SIMDE_FLOAT32_C(  -602.24), SIMDE_FLOAT32_C(   885.83),
        SIMDE_FLOAT32_C(   450.10), SIMDE_FLOAT32_C(  -580.76), SIMDE_FLOAT32_C(   -43.35), SIMDE_FLOAT32_C(  -176.72),
        SIMDE_FLOAT32_C(   697.79), SIMDE_FLOAT32_C(  -514.98), SIMDE_FLOAT32_C(  -539.79), SIMDE_FLOAT32_C(    81.80) } },
    {
        { { SIMDE_FLOAT32_C(   667.61), SIMDE_FLOAT32_C(  -256.69), SIMDE_FLOAT32_C(  -137.14), SIMDE_FLOAT32_C(  -987.69) },
          { SIMDE_FLOAT32_C(  -283.13), SIMDE_FLOAT32_C(    43.43), SIMDE_FLOAT32_C(   498.39), SIMDE_FLOAT32_C(   225.83) },
          { SIMDE_FLOAT32_C(   942.57), SIMDE_FLOAT32_C(   724.97), SIMDE_FLOAT32_C(  -337.87), SIMDE_FLOAT32_C(   623.53) },
          { SIMDE_FLOAT32_C(   700.19), SIMDE_FLOAT32_C(  -982.34), SIMDE_FLOAT32_C(   865.96), SIMDE_FLOAT32_C(   115.48) } },
      { SIMDE_FLOAT32_C(   667.61), SIMDE_FLOAT32_C(  -256.69), SIMDE_FLOAT32_C(  -137.14), SIMDE_FLOAT32_C(  -987.69),
        SIMDE_FLOAT32_C(  -283.13), SIMDE_FLOAT32_C(    43.43), SIMDE_FLOAT32_C(   498.39), SIMDE_FLOAT32_C(   225.83),
        SIMDE_FLOAT32_C(   942.57), SIMDE_FLOAT32_C(   724.97), SIMDE_FLOAT32_C(  -337.87), SIMDE_FLOAT32_C(   623.53),
        SIMDE_FLOAT32_C(   700.19), SIMDE_FLOAT32_C(  -982.34), SIMDE_FLOAT32_C(   865.96), SIMDE_FLOAT32_C(   115.48) } },
    {
        { { SIMDE_FLOAT32_C(  -111.31), SIMDE_FLOAT32_C(  -898.40), SIMDE_FLOAT32_C(  -317.15), SIMDE_FLOAT32_C(   646.34) },
          { SIMDE_FLOAT32_C(  -280.54), SIMDE_FLOAT32_C(    80.61), SIMDE_FLOAT32_C(   532.18), SIMDE_FLOAT32_C(  -830.44) },
          { SIMDE_FLOAT32_C(   499.86), SIMDE_FLOAT32_C(  -511.17), SIMDE_FLOAT32_C(    -7.16), SIMDE_FLOAT32_C(   197.65) },
          { SIMDE_FLOAT32_C(   -26.15), SIMDE_FLOAT32_C(   453.05), SIMDE_FLOAT32_C(  -720.54), SIMDE_FLOAT32_C(  -358.54) } },
      { SIMDE_FLOAT32_C(  -111.31), SIMDE_FLOAT32_C(  -898.40), SIMDE_FLOAT32_C(  -317.15), SIMDE_FLOAT32_C(   646.34),
        SIMDE_FLOAT32_C(  -280.54), SIMDE_FLOAT32_C(    80.61), SIMDE_FLOAT32_C(   532.18), SIMDE_FLOAT32_C(  -830.44),
        SIMDE_FLOAT32_C(   499.86), SIMDE_FLOAT32_C(  -511.17), SIMDE_FLOAT32_C(    -7.16), SIMDE_FLOAT32_C(   197.65),
        SIMDE_FLOAT32_C(   -26.15), SIMDE_FLOAT32_C(   453.05), SIMDE_FLOAT32_C(  -720.54), SIMDE_FLOAT32_C(  -358.54) } },
    {
        { { SIMDE_FLOAT32_C(  -803.64), SIMDE_FLOAT32_C(   142.31), SIMDE_FLOAT32_C(  -346.23), SIMDE_FLOAT32_C(   -86.77) },
          { SIMDE_FLOAT32_C(  -814.25), SIMDE_FLOAT32_C(  -847.83), SIMDE_FLOAT32_C(  -860.93), SIMDE_FLOAT32_C(  -871.68) },
          { SIMDE_FLOAT32_C(   877.13), SIMDE_FLOAT32_C(  -198.80), SIMDE_FLOAT32_C(   751.84), SIMDE_FLOAT32_C(   577.32) },
          { SIMDE_FLOAT32_C(  -181.14), SIMDE_FLOAT32_C(   617.81), SIMDE_FLOAT32_C(  -307.19), SIMDE_FLOAT32_C(   707.55) } },
      { SIMDE_FLOAT32_C(  -803.64), SIMDE_FLOAT32_C(   142.31), SIMDE_FLOAT32_C(  -346.23), SIMDE_FLOAT32_C(   -86.77),
        SIMDE_FLOAT32_C(  -814.25), SIMDE_FLOAT32_C(  -847.83), SIMDE_FLOAT32_C(  -860.93), SIMDE_FLOAT32_C(  -871.68),
        SIMDE_FLOAT32_C(   877.13), SIMDE_FLOAT32_C(  -198.80), SIMDE_FLOAT32_C(   751.84), SIMDE_FLOAT32_C(   577.32),
        SIMDE_FLOAT32_C(  -181.14), SIMDE_FLOAT32_C(   617.81), SIMDE_FLOAT32_C(  -307.19), SIMDE_FLOAT32_C(   707.55) } },
    {
        { { SIMDE_FLOAT32_C(   719.41), SIMDE_FLOAT32_C(   375.66), SIMDE_FLOAT32_C(   353.89), SIMDE_FLOAT32_C(  -561.13) },
          { SIMDE_FLOAT32_C(  -543.72), SIMDE_FLOAT32_C(  -113.93), SIMDE_FLOAT32_C(  -391.58), SIMDE_FLOAT32_C(   956.14) },
          { SIMDE_FLOAT32_C(   374.90), SIMDE_FLOAT32_C(   601.26), SIMDE_FLOAT32_C(   153.79), SIMDE_FLOAT32_C(  -651.25) },
          { SIMDE_FLOAT32_C(    54.31), SIMDE_FLOAT32_C(   433.24), SIMDE_FLOAT32_C(    -9.79), SIMDE_FLOAT32_C(   250.67) } },
      { SIMDE_FLOAT32_C(   719.41), SIMDE_FLOAT32_C(   375.66), SIMDE_FLOAT32_C(   353.89), SIMDE_FLOAT32_C(  -561.13),
        SIMDE_FLOAT32_C(  -543.72), SIMDE_FLOAT32_C(  -113.93), SIMDE_FLOAT32_C(  -391.58), SIMDE_FLOAT32_C(   956.14),
        SIMDE_FLOAT32_C(   374.90), SIMDE_FLOAT32_C(   601.26), SIMDE_FLOAT32_C(   153.79), SIMDE_FLOAT32_C(  -651.25),
        SIMDE_FLOAT32_C(    54.31), SIMDE_FLOAT32_C(   433.24), SIMDE_FLOAT32_C(    -9.79), SIMDE_FLOAT32_C(   250.67) } },
    {
        { { SIMDE_FLOAT32_C(  -424.44), SIMDE_FLOAT32_C(   643.98), SIMDE_FLOAT32_C(  -836.09), SIMDE_FLOAT32_C(  -238.69) },
          { SIMDE_FLOAT32_C(   796.14), SIMDE_FLOAT32_C(  -697.03), SIMDE_FLOAT32_C(  -110.38), SIMDE_FLOAT32_C(   673.28) },
          { SIMDE_FLOAT32_C(   104.17), SIMDE_FLOAT32_C(  -358.53), SIMDE_FLOAT32_C(   250.60), SIMDE_FLOAT32_C(   923.03) },
          { SIMDE_FLOAT32_C(  -740.72), SIMDE_FLOAT32_C(   943.41), SIMDE_FLOAT32_C(   630.57), SIMDE_FLOAT32_C(   978.68) } },
      { SIMDE_FLOAT32_C(  -424.44), SIMDE_FLOAT32_C(   643.98), SIMDE_FLOAT32_C(  -836.09), SIMDE_FLOAT32_C(  -238.69),
        SIMDE_FLOAT32_C(   796.14), SIMDE_FLOAT32_C(  -697.03), SIMDE_FLOAT32_C(  -110.38), SIMDE_FLOAT32_C(   673.28),
        SIMDE_FLOAT32_C(   104.17), SIMDE_FLOAT32_C(  -358.53), SIMDE_FLOAT32_C(   250.60), SIMDE_FLOAT32_C(   923.03),
        SIMDE_FLOAT32_C(  -740.72), SIMDE_FLOAT32_C(   943.41), SIMDE_FLOAT32_C(   630.57), SIMDE_FLOAT32_C(   978.68) } },
    {
        { { SIMDE_FLOAT32_C(   319.07), SIMDE_FLOAT32_C(   -15.53), SIMDE_FLOAT32_C(  -582.45), SIMDE_FLOAT32_C(   775.35) },
          { SIMDE_FLOAT32_C(   870.54), SIMDE_FLOAT32_C(    25.97), SIMDE_FLOAT32_C(   731.48), SIMDE_FLOAT32_C(   245.44) },
          { SIMDE_FLOAT32_C(  -372.76), SIMDE_FLOAT32_C(  -114.73), SIMDE_FLOAT32_C(   594.19), SIMDE_FLOAT32_C(   681.55) },
          { SIMDE_FLOAT32_C(  -681.49), SIMDE_FLOAT32_C(  -415.61), SIMDE_FLOAT32_C(   -67.78), SIMDE_FLOAT32_C(  -105.93) } },
      { SIMDE_FLOAT32_C(   319.07), SIMDE_FLOAT32_C(   -15.53), SIMDE_FLOAT32_C(  -582.45), SIMDE_FLOAT32_C(   775.35),
        SIMDE_FLOAT32_C(   870.54), SIMDE_FLOAT32_C(    25.97), SIMDE_FLOAT32_C(   731.48), SIMDE_FLOAT32_C(   245.44),
        SIMDE_FLOAT32_C(  -372.76), SIMDE_FLOAT32_C(  -114.73), SIMDE_FLOAT32_C(   594.19), SIMDE_FLOAT32_C(   681.55),
        SIMDE_FLOAT32_C(  -681.49), SIMDE_FLOAT32_C(  -415.61), SIMDE_FLOAT32_C(   -67.78), SIMDE_FLOAT32_C(  -105.93) } },
    {
        { { SIMDE_FLOAT32_C(  -771.63), SIMDE_FLOAT32_C(    96.13), SIMDE_FLOAT32_C(   655.38), SIMDE_FLOAT32_C(  -975.48) },
          { SIMDE_FLOAT32_C(   399.10), SIMDE_FLOAT32_C(  -454.99), SIMDE_FLOAT32_C(   697.80), SIMDE_FLOAT32_C(  -496.73) },
          { SIMDE_FLOAT32_C(   186.48), SIMDE_FLOAT32_C(   -51.60), SIMDE_FLOAT32_C(  -573.70), SIMDE_FLOAT32_C(   445.75) },
          { SIMDE_FLOAT32_C(  -108.20), SIMDE_FLOAT32_C(  -943.13), SIMDE_FLOAT32_C(   424.44), SIMDE_FLOAT32_C(  -789.12) } },
      { SIMDE_FLOAT32_C(  -771.63), SIMDE_FLOAT32_C(    96.13), SIMDE_FLOAT32_C(   655.38), SIMDE_FLOAT32_C(  -975.48),
        SIMDE_FLOAT32_C(   399.10), SIMDE_FLOAT32_C(  -454.99), SIMDE_FLOAT32_C(   697.80), SIMDE_FLOAT32_C(  -496.73),
        SIMDE_FLOAT32_C(   186.48), SIMDE_FLOAT32_C(   -51.60), SIMDE_FLOAT32_C(  -573.70), SIMDE_FLOAT32_C(   445.75),
        SIMDE_FLOAT32_C(  -108.20), SIMDE_FLOAT32_C(  -943.13), SIMDE_FLOAT32_C(   424.44), SIMDE_FLOAT32_C(  -789.12) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4x4_t r_ = { { simde_vld1q_f32(test_vec[i].r[0]),
                                 simde_vld1q_f32(test_vec[i].r[1]),
                                 simde_vld1q_f32(test_vec[i].r[2]),
                                 simde_vld1q_f32(test_vec[i].r[3]) } };

    simde_float32 a_[16];
    simde_vst1q_f32_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t c = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4_t d = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f);
    simde_float32x4x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_f32x4x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32 buf[16];
    simde_vst1q_f32_x4(buf, e);

    simde_test_codegen_write_vf32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_f64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r[4][2];
    simde_float64 a[8];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(    41.34), SIMDE_FLOAT64_C(   841.99) },
          { SIMDE_FLOAT64_C(   986.22), SIMDE_FLOAT64_C(   -88.12) },
          { SIMDE_FLOAT64_C(  -132.04), SIMDE_FLOAT64_C(   717.70) },
          { SIMDE_FLOAT64_C(  -842.69), SIMDE_FLOAT64_C(   495.20) } },
      { SIMDE_FLOAT64_C(    41.34), SIMDE_FLOAT64_C(   841.99), SIMDE_FLOAT64_C(   986.22), SIMDE_FLOAT64_C(   -88.12),
        SIMDE_FLOAT64_C(  -132.04), SIMDE_FLOAT64_C(   717.70), SIMDE_FLOAT64_C(  -842.69), SIMDE_FLOAT64_C(   495.20) } },
    {
        { { SIMDE_FLOAT64_C(  -397.02), SIMDE_FLOAT64_C(   751.50) },
          { SIMDE_FLOAT64_C(   176.75), SIMDE_FLOAT64_C(   -78.51) },
          { SIMDE_FLOAT64_C(  -664.11), SIMDE_FLOAT64_C(  -891.03) },
          { SIMDE_FLOAT64_C(   815.56), SIMDE_FLOAT64_C(  -435.73) } },
      { SIMDE_FLOAT64_C(  -397.02), SIMDE_FLOAT64_C(   751.50), SIMDE_FLOAT64_C(   176.75), SIMDE_FLOAT64_C(   -78.51),
        SIMDE_FLOAT64_C(  -664.11), SIMDE_FLOAT64_C(  -891.03), SIMDE_FLOAT64_C(   815.56), SIMDE_FLOAT64_C(  -435.73) } },
    {
        { { SIMDE_FLOAT64_C(   205.10), SIMDE_FLOAT64_C(   470.95) },
          { SIMDE_FLOAT64_C(  -411.22), SIMDE_FLOAT64_C(  -395.80) },
          { SIMDE_FLOAT64_C(  -984.05), SIMDE_FLOAT64_C(  -713.42) },
          { SIMDE_FLOAT64_C(   107.47), SIMDE_FLOAT64_C(   202.43) } },
      { SIMDE_FLOAT64_C(   205.10), SIMDE_FLOAT64_C(   470.95), SIMDE_FLOAT64_C(  -411.22), SIMDE_FLOAT64_C(  -395.80),
        SIMDE_FLOAT64_C(  -984.05), SIMDE_FLOAT64_C(  -713.42), SIMDE_FLOAT64_C(   107.47), SIMDE_FLOAT64_C(   202.43) } },
    {
        { { SIMDE_FLOAT64_C(   234.98), SIMDE_FLOAT64_C(   533.77) },
          { SIMDE_FLOAT64_C(  -351.82), SIMDE_FLOAT64_C(  -873.22) },
          { SIMDE_FLOAT64_C(   590.65), SIMDE_FLOAT64_C(  -927.38) },
          { SIMDE_FLOAT64_C(  -662.34), SIMDE_FLOAT64_C(  -368.01) } },
      { SIMDE_FLOAT64_C(   234.98), SIMDE_FLOAT64_C(   533.77), SIMDE_FLOAT64_C(  -351.82), SIMDE_FLOAT64_C(  -873.22),
        SIMDE_FLOAT64_C(   590.65), SIMDE_FLOAT64_C(  -927.38), SIMDE_FLOAT64_C(  -662.34), SIMDE_FLOAT64_C(  -368.01) } },
    {
        { { SIMDE_FLOAT64_C(   914.61), SIMDE_FLOAT64_C(  -676.12) },
          { SIMDE_FLOAT64_C(   543.86), SIMDE_FLOAT64_C(  -217.43) },
          { SIMDE_FLOAT64_C(  -958.42), SIMDE_FLOAT64_C(   701.17) },
          { SIMDE_FLOAT64_C(  -722.23), SIMDE_FLOAT64_C(  -355.44) } },
      { SIMDE_FLOAT64_C(   914.61), SIMDE_FLOAT64_C(  -676.12), SIMDE_FLOAT64_C(   543.86), SIMDE_FLOAT64_C(  -217.43),
        SIMDE_FLOAT64_C(  -958.42), SIMDE_FLOAT64_C(   701.17), SIMDE_FLOAT64_C(  -722.23), SIMDE_FLOAT64_C(  -355.44) } },
    {
        { { SIMDE_FLOAT64_C(   452.67), SIMDE_FLOAT64_C(   454.52) },
          { SIMDE_FLOAT64_C(   566.05), SIMDE_FLOAT64_C(   788.57) },
          { SIMDE_FLOAT64_C(   563.49), SIMDE_FLOAT64_C(   381.62) },
          { SIMDE_FLOAT64_C(  -647.16), SIMDE_FLOAT64_C(  -231.41) } },
      { SIMDE_FLOAT64_C(   452.67), SIMDE_FLOAT64_C(   454.52), SIMDE_FLOAT64_C(   566.05), SIMDE_FLOAT64_C(   788.57),
        SIMDE_FLOAT64_C(   563.49), SIMDE_FLOAT64_C(   381.62), SIMDE_FLOAT64_C(  -647.16), SIMDE_FLOAT64_C(  -231.41) } },
    {
        { { SIMDE_FLOAT64_C(  -147.44), SIMDE_FLOAT64_C(   -58.38) },
          { SIMDE_FLOAT64_C(   372.79), SIMDE_FLOAT64_C(  -131.49) },
          { SIMDE_FLOAT64_C(   228.20), SIMDE_FLOAT64_C(  -519.73) },
          { SIMDE_FLOAT64_C(  -929.06), SIMDE_FLOAT64_C(  -536.82) } },
      { SIMDE_FLOAT64_C(  -147.44), SIMDE_FLOAT64_C(   -58.38), SIMDE_FLOAT64_C(   372.79), SIMDE_FLOAT64_C(  -131.49),
        SIMDE_FLOAT64_C(   228.20), SIMDE_FLOAT64_C(  -519.73), SIMDE_FLOAT64_C(  -929.06), SIMDE_FLOAT64_C(  -536.82) } },
    {
        { { SIMDE_FLOAT64_C(  -985.96), SIMDE_FLOAT64_C(  -280.88) },
          { SIMDE_FLOAT64_C(  -410.04), SIMDE_FLOAT64_C(   604.69) },
          { SIMDE_FLOAT64_C(  -208.26), SIMDE_FLOAT64_C(   -72.39) },
          { SIMDE_FLOAT64_C(  -763.32), SIMDE_FLOAT64_C(  -293.65) } },
      { SIMDE_FLOAT64_C(  -985.96), SIMDE_FLOAT64_C(  -280.88), SIMDE_FLOAT64_C(  -410.04), SIMDE_FLOAT64_C(   604.69),
        SIMDE_FLOAT64_C(  -208.26), SIMDE_FLOAT64_C(   -72.39), SIMDE_FLOAT64_C(  -763.32), SIMDE_FLOAT64_C(  -293.65) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2x4_t r_ = { { simde_vld1q_f64(test_vec[i].r[0]),
                                 simde_vld1q_f64(test_vec[i].r[1]),
                                 simde_vld1q_f64(test_vec[i].r[2]),
                                 simde_vld1q_f64(test_vec[i].r[3]) } };

    simde_float64 a_[8];
    simde_vst1q_f64_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t c = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2_t d = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0);
    simde_float64x2x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_f64x2x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64 buf[8];
    simde_vst1q_f64_x4(buf, e);

    simde_test_codegen_write_vf64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s8_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[4][16];
    int8_t a[64];
  } test_vec[] = {
    {
        { {  INT8_C(  23),  INT8_C(  29), -INT8_C(  65), -INT8_C(  63),  INT8_C(  50), -INT8_C(  49),  INT8_C(  88),      INT8_MAX,
             INT8_C(  36), -INT8_C(  70), -INT8_C( 112),  INT8_C( 119),  INT8_C(  74),  INT8_C(  54), -INT8_C(  42),  INT8_C( 116) },
          {  INT8_C(   7), -INT8_C( 127),  INT8_C(   3),  INT8_C(  13),  INT8_C(  52), -INT8_C( 120),  INT8_C(  43), -INT8_C( 125),
            -INT8_C(  85), -INT8_C(  34), -INT8_C(  94), -INT8_C(  83), -INT8_C(  62), -INT8_C(  21), -INT8_C(   8), -INT8_C(  38) },
          {  INT8_C(   8), -INT8_C(  72), -INT8_C( 101),  INT8_C(  58), -INT8_C( 121), -INT8_C(  13), -INT8_C(  71), -INT8_C(  85),
            -INT8_C(  83),  INT8_C(  74),  INT8_C(  34), -INT8_C(   9),      INT8_MIN, -INT8_C(   7),  INT8_C( 108), -INT8_C( 121) },
          {  INT8_C( 122),  INT8_C( 111), -INT8_C( 108), -INT8_C(  82), -INT8_C(   9), -INT8_C(  65),  INT8_C(  49), -INT8_C(  93),
            -INT8_C(  99), -INT8_C(  44),  INT8_C(  80),  INT8_C(  96), -INT8_C(  65),  INT8_C(  72),  INT8_C(  58), -INT8_C(  57) } },
      {  INT8_C(  23),  INT8_C(  29), -INT8_C(  65), -INT8_C(  63),  INT8_C(  50), -INT8_C(  49),  INT8_C(  88),      INT8_MAX,
         INT8_C(  36), -INT8_C(  70), -INT8_C( 112),  INT8_C( 119),  INT8_C(  74),  INT8_C(  54), -INT8_C(  42),  INT8_C( 116),
         INT8_C(   7), -INT8_C( 127),  INT8_C(   3),  INT8_C(  13),  INT8_C(  52), -INT8_C( 120),  INT8_C(  43), -INT8_C( 125),
        -INT8_C(  85), -INT8_C(  34), -INT8_C(  94), -INT8_C(  83), -INT8_C(  62), -INT8_C(  21), -INT8_C(   8), -INT8_C(  38),
         INT8_C(   8), -INT8_C(  72), -INT8_C( 101),  INT8_C(  58), -INT8_C( 121), -INT8_C(  13), -INT8_C(  71), -INT8_C(  85),
        -INT8_C(  83),  INT8_C(  74),  INT8_C(  34), -INT8_C(   9),      INT8_MIN, -INT8_C(   7),  INT8_C( 108), -INT8_C( 121),
         INT8_C( 122),  INT8_C( 111), -INT8_C( 108), -INT8_C(  82), -INT8_C(   9), -INT8_C(  65),  INT8_C(  49), -INT8_C(  93),
        -INT8_C(  99), -INT8_C(  44),  INT8_C(  80),  INT8_C(  96), -INT8_C(  65),  INT8_C(  72),  INT8_C(  58), -INT8_C(  57) } },
    {
        { {  INT8_C(   0), -INT8_C(  43),  INT8_C(   2), -INT8_C( 121), -INT8_C(  56), -INT8_C(  69),  INT8_C(  51),  INT8_C( 118),
             INT8_C(   5),  INT8_C(  85),  INT8_C( 109), -INT8_C( 123),  INT8_C(  78), -INT8_C(  39),  INT8_C(  12), -INT8_C(  56) },
          {  INT8_C(  73), -INT8_C(  95),  INT8_C( 119),  INT8_C(  64),  INT8_C(  96), -INT8_C(  88), -INT8_C(  29), -INT8_C(   2),
             INT8_C( 124),  INT8_C(  51),  INT8_C(  94),  INT8_C(  59),  INT8_C( 124), -INT8_C( 104),  INT8_C(   3),  INT8_C( 124) },
          {  INT8_C( 109),  INT8_C(   5),  INT8_C(   4),  INT8_C(  53), -INT8_C(  64),  INT8_C(  55), -INT8_C(  85), -INT8_C(  58),
            -INT8_C( 116),  INT8_C(  25),  INT8_C(  75), -INT8_C(  37), -INT8_C(  14),  INT8_C(  88), -INT8_C(  93),  INT8_C(  59) },
          { -INT8_C(   7),  INT8_C(  26),  INT8_C( 124),  INT8_C(  89), -INT8_C(  61),  INT8_C(  95),  INT8_C(  87),  INT8_C(  63),
            -INT8_C( 109), -INT8_C(  75),  INT8_C( 123),  INT8_C(  15),  INT8_C(  77),  INT8_C( 126), -INT8_C( 117), -INT8_C(  70) } },
      {  INT8_C(   0), -INT8_C(  43),  INT8_C(   2), -INT8_C( 121), -INT8_C(  56), -INT8_C(  69),  INT8_C(  51),  INT8_C( 118),
         INT8_C(   5),  INT8_C(  85),  INT8_C( 109), -INT8_C( 123),  INT8_C(  78), -INT8_C(  39),  INT8_C(  12), -INT8_C(  56),
         INT8_C(  73), -INT8_C(  95),  INT8_C( 119),  INT8_C(  64),  INT8_C(  96), -INT8_C(  88), -INT8_C(  29), -INT8_C(   2),
         INT8_C( 124),  INT8_C(  51),  INT8_C(  94),  INT8_C(  59),  INT8_C( 124), -INT8_C( 104),  INT8_C(   3),  INT8_C( 124),
         INT8_C( 109),  INT8_C(   5),  INT8_C(   4),  INT8_C(  53), -INT8_C(  64),  INT8_C(  55), -INT8_C(  85), -INT8_C(  58),
        -INT8_C( 116),  INT8_C(  25),  INT8_C(  75), -INT8_C(  37), -INT8_C(  14),  INT8_C(  88), -INT8_C(  93),  INT8_C(  59),
        -INT8_C(   7),  INT8_C(  26),  INT8_C( 124),  INT8_C(  89), -INT8_C(  61),  INT8_C(  95),  INT8_C(  87),  INT8_C(  63),
        -INT8_C( 109), -INT8_C(  75),  INT8_C( 123),  INT8_C(  15),  INT8_C(  77),  INT8_C( 126), -INT8_C( 117), -INT8_C(  70) } },
    {
        { { -INT8_C( 125), -INT8_C( 113), -INT8_C(  16),  INT8_C(  67), -INT8_C(  58), -INT8_C( 101),  INT8_C(   9),  INT8_C(  83),
            -INT8_C(  76),  INT8_C(  85),  INT8_C(  46), -INT8_C(  89), -INT8_C(  83), -INT8_C(  47), -INT8_C(  30), -INT8_C(  90) },
          { -INT8_C(  20),  INT8_C(  94), -INT8_C(   1), -INT8_C(  81), -INT8_C(  66),  INT8_C(  87), -INT8_C(  18),  INT8_C(  81),
             INT8_C(  12),  INT8_C( 105),  INT8_C(  96),  INT8_C(  90), -INT8_C(  25), -INT8_C(  21),  INT8_C(  20),  INT8_C( 106) },
          {  INT8_C( 123),  INT8_C(   4), -INT8_C(  82),  INT8_C(  65), -INT8_C(  96), -INT8_C(  73), -INT8_C( 108),  INT8_C(  84),
             INT8_C(  12), -INT8_C(  62), -INT8_C(   5), -INT8_C(  71), -INT8_C( 108), -INT8_C(  34),  INT8_C(  95),      INT8_MIN },
          {  INT8_C(  60),  INT8_C(  95),  INT8_C(  47), -INT8_C(   6), -INT8_C(  74),  INT8_C(  29),  INT8_C(  75), -INT8_C(  62),
            -INT8_C( 121), -INT8_C(  85),  INT8_C(  28),  INT8_C( 110), -INT8_C( 105),  INT8_C(  49), -INT8_C(  39),  INT8_C(  18) } },
      { -INT8_C( 125), -INT8_C( 113), -INT8_C(  16),  INT8_C(  67), -INT8_C(  58), -INT8_C( 101),  INT8_C(   9),  INT8_C(  83),
        -INT8_C(  76),  INT8_C(  85),  INT8_C(  46), -INT8_C(  89), -INT8_C(  83), -INT8_C(  47), -INT8_C(  30), -INT8_C(  90),
        -INT8_C(  20),  INT8_C(  94), -INT8_C(   1), -INT8_C(  81), -INT8_C(  66),  INT8_C(  87), -INT8_C(  18),  INT8_C(  81),
         INT8_C(  12),  INT8_C( 105),  INT8_C(  96),  INT8_C(  90), -INT8_C(  25), -INT8_C(  21),  INT8_C(  20),  INT8_C( 106),
         INT8_C( 123),  INT8_C(   4), -INT8_C(  82),  INT8_C(  65), -INT8_C(  96), -INT8_C(  73), -INT8_C( 108),  INT8_C(  84),
         INT8_C(  12), -INT8_C(  62), -INT8_C(   5), -INT8_C(  71), -INT8_C( 108), -INT8_C(  34),  INT8_C(  95),      INT8_MIN,
         INT8_C(  60),  INT8_C(  95),  INT8_C(  47), -INT8_C(   6), -INT8_C(  74),  INT8_C(  29),  INT8_C(  75), -INT8_C(  62),
        -INT8_C( 121), -INT8_C(  85),  INT8_C(  28),  INT8_C( 110), -INT8_C( 105),  INT8_C(  49), -INT8_C(  39),  INT8_C(  18) } },
    {
        { {  INT8_C(  53), -INT8_C( 121),  INT8_C(  83), -INT8_C(  43),  INT8_C(  62), -INT8_C(  24),  INT8_C(  42),  INT8_C(  75),
            -INT8_C(  86),  INT8_C(  37),  INT8_C(   4),  INT8_C(  62),  INT8_C(   3),  INT8_C( 100), -INT8_C(  66),  INT8_C(  64) },
          { -INT8_C(  61), -INT8_C(  19),  INT8_C(  58),  INT8_C( 121),  INT8_C(  11), -INT8_C( 122),  INT8_C(  59), -INT8_C( 110),
             INT8_C(  49),  INT8_C(  88),  INT8_C(   0), -INT8_C(  56), -INT8_C( 119), -INT8_C(  39), -INT8_C(  38), -INT8_C(  66) },
          {  INT8_C(  96),  INT8_C(  46), -INT8_C( 108), -INT8_C(  97),  INT8_C(  22), -INT8_C(  66), -INT8_C(  22), -INT8_C(  64),
            -INT8_C(  29), -INT8_C(  18), -INT8_C(   1), -INT8_C(  25),  INT8_C(  82), -INT8_C(  67),  INT8_C(  39),  INT8_C(  21) },
          { -INT8_C(  85),  INT8_C(  97), -INT8_C( 114), -INT8_C(  74), -INT8_C(  25), -INT8_C(  54),  INT8_C(  72),  INT8_C(  25),
             INT8_C(  34),  INT8_C(  72), -INT8_C(  31), -INT8_C(  85),  INT8_C(  34), -INT8_C(  68),  INT8_C( 105), -INT8_C( 126) } },
      {  INT8_C(  53), -INT8_C( 121),  INT8_C(  83), -INT8_C(  43),  INT8_C(  62), -INT8_C(  24),  INT8_C(  42),  INT8_C(  75),
        -INT8_C(  86),  INT8_C(  37),  INT8_C(   4),  INT8_C(  62),  INT8_C(   3),  INT8_C( 100), -INT8_C(  66),  INT8_C(  64),
        -INT8_C(  61), -INT8_C(  19),  INT8_C(  58),  INT8_C( 121),  INT8_C(  11), -INT8_C( 122),  INT8_C(  59), -INT8_C( 110),
         INT8_C(  49),  INT8_C(  88),  INT8_C(   0), -INT8_C(  56), -INT8_C( 119), -INT8_C(  39), -INT8_C(  38), -INT8_C(  66),
         INT8_C(  96),  INT8_C(  46), -INT8_C( 108), -INT8_C(  97),  INT8_C(  22), -INT8_C(  66), -INT8_C(  22), -INT8_C(  64),
        -INT8_C(  29), -INT8_C(  18), -INT8_C(   1), -INT8_C(  25),  INT8_C(  82), -INT8_C(  67),  INT8_C(  39),  INT8_C(  21),
        -INT8_C(  85),  INT8_C(  97), -INT8_C( 114), -INT8_C(  74), -INT8_C(  25), -INT8_C(  54),  INT8_C(  72),  INT8_C(  25),
         INT8_C(  34),  INT8_C(  72), -INT8_C(  31), -INT8_C(  85),  INT8_C(  34), -INT8_C(  68),  INT8_C( 105), -INT8_C( 126) } },
    {
        { { -INT8_C(  22), -INT8_C(   3),  INT8_C(  33),  INT8_C(   0), -INT8_C(  69),  INT8_C(  11), -INT8_C(  64), -INT8_C(  97),
            -INT8_C(   6), -INT8_C(  65), -INT8_C( 122),  INT8_C(  76),  INT8_C( 125), -INT8_C(  83),  INT8_C(  98),  INT8_C(  40) },
          {  INT8_C(  14), -INT8_C(  16), -INT8_C(  34), -INT8_C(  10), -INT8_C(  70),  INT8_C(  38),  INT8_C(  15), -INT8_C(  36),
             INT8_C( 110), -INT8_C(  16), -INT8_C( 121), -INT8_C( 112), -INT8_C(  84), -INT8_C(  15),  INT8_C(  19), -INT8_C( 106) },
          { -INT8_C(  18),  INT8_C(  52), -INT8_C( 106), -INT8_C(  86),  INT8_C(  64),  INT8_C(  87),  INT8_C(  73),  INT8_C(  58),
             INT8_C(  22), -INT8_C(  49), -INT8_C( 122), -INT8_C( 109),  INT8_C( 124), -INT8_C(  24), -INT8_C(  69), -INT8_C( 118) },
          { -INT8_C(  39), -INT8_C( 103),      INT8_MIN, -INT8_C( 109), -INT8_C(  65), -INT8_C( 113),  INT8_C( 112),  INT8_C(  46),
                 INT8_MIN, -INT8_C(   9), -INT8_C(  66),  INT8_C(  44), -INT8_C(  24), -INT8_C(  47), -INT8_C(  61), -INT8_C(  41) } },
      { -INT8_C(  22), -INT8_C(   3),  INT8_C(  33),  INT8_C(   0), -INT8_C(  69),  INT8_C(  11), -INT8_C(  64), -INT8_C(  97),
        -INT8_C(   6), -INT8_C(  65), -INT8_C( 122),  INT8_C(  76),  INT8_C( 125), -INT8_C(  83),  INT8_C(  98),  INT8_C(  40),
         INT8_C(  14), -INT8_C(  16), -INT8_C(  34), -INT8_C(  10), -INT8_C(  70),  INT8_C(  38),  INT8_C(  15), -INT8_C(  36),
         INT8_C( 110), -INT8_C(  16), -INT8_C( 121), -INT8_C( 112), -INT8_C(  84), -INT8_C(  15),  INT8_C(  19), -INT8_C( 106),
        -INT8_C(  18),  INT8_C(  52), -INT8_C( 106), -INT8_C(  86),  INT8_C(  64),  INT8_C(  87),  INT8_C(  73),  INT8_C(  58),
         INT8_C(  22), -INT8_C(  49), -INT8_C( 122), -INT8_C( 109),  INT8_C( 124), -INT8_C(  24), -INT8_C(  69), -INT8_C( 118),
        -INT8_C(  39), -INT8_C( 103),      INT8_MIN, -INT8_C( 109), -INT8_C(  65), -INT8_C( 113),  INT8_C( 112),  INT8_C(  46),
             INT8_MIN, -INT8_C(   9), -INT8_C(  66),  INT8_C(  44), -INT8_C(  24), -INT8_C(  47), -INT8_C(  61), -INT8_C(  41) } },
    {
        { {  INT8_C(   6),  INT8_C(  89), -INT8_C( 127),  INT8_C(  70), -INT8_C(  80), -INT8_C(  54),      INT8_MIN, -INT8_C(  57),
            -INT8_C( 103),  INT8_C(   6),  INT8_C(  90),  INT8_C(  21), -INT8_C(  17),  INT8_C(  22), -INT8_C(  97), -INT8_C(  56) },
          { -INT8_C(  81),  INT8_C(  32),  INT8_C(  91),  INT8_C( 111), -INT8_C(  81), -INT8_C(  53), -INT8_C(  99),  INT8_C(  47),
            -INT8_C(  61),  INT8_C(  91),  INT8_C(  92), -INT8_C(  85),  INT8_C(  45),  INT8_C(  31), -INT8_C( 126),  INT8_C(  51) },
          {  INT8_C( 120),  INT8_C(   3),  INT8_C( 121),  INT8_C(  41), -INT8_C(  51), -INT8_C(   7), -INT8_C(  16),  INT8_C( 102),
            -INT8_C(   1),  INT8_C(  74),  INT8_C( 123), -INT8_C(  18),  INT8_C(  96),  INT8_C(  27), -INT8_C(  74),  INT8_C(  16) },
          {  INT8_C(  59),  INT8_C(  18),      INT8_MAX, -INT8_C(  22), -INT8_C(  35),  INT8_C(  28),  INT8_C(  26), -INT8_C(  96),
             INT8_C( 119),  INT8_C( 118),  INT8_C(  76), -INT8_C(  92), -INT8_C( 107), -INT8_C(  50), -INT8_C(  41),  INT8_C(  13) } },
      {  INT8_C(   6),  INT8_C(  89), -INT8_C( 127),  INT8_C(  70), -INT8_C(  80), -INT8_C(  54),      INT8_MIN, -INT8_C(  57),
        -INT8_C( 103),  INT8_C(   6),  INT8_C(  90),  INT8_C(  21), -INT8_C(  17),  INT8_C(  22), -INT8_C(  97), -INT8_C(  56),
        -INT8_C(  81),  INT8_C(  32),  INT8_C(  91),  INT8_C( 111), -INT8_C(  81), -INT8_C(  53), -INT8_C(  99),  INT8_C(  47),
        -INT8_C(  61),  INT8_C(  91),  INT8_C(  92), -INT8_C(  85),  INT8_C(  45),  INT8_C(  31), -INT8_C( 126),  INT8_C(  51),
         INT8_C( 120),  INT8_C(   3),  INT8_C( 121),  INT8_C(  41), -INT8_C(  51), -INT8_C(   7), -INT8_C(  16),  INT8_C( 102),
        -INT8_C(   1),  INT8_C(  74),  INT8_C( 123), -INT8_C(  18),  INT8_C(  96),  INT8_C(  27), -INT8_C(  74),  INT8_C(  16),
         INT8_C(  59),  INT8_C(  18),      INT8_MAX, -INT8_C(  22), -INT8_C(  35),  INT8_C(  28),  INT8_C(  26), -INT8_C(  96),
         INT8_C( 119),  INT8_C( 118),  INT8_C(  76), -INT8_C(  92), -INT8_C( 107), -INT8_C(  50), -INT8_C(  41),  INT8_C(  13) } },
    {
        { { -INT8_C(  46),  INT8_C(  80),  INT8_C(  54), -INT8_C(  97),  INT8_C(  73),  INT8_C(  38),  INT8_C(   6),  INT8_C(  73),
             INT8_C( 113), -INT8_C( 127),  INT8_C(  55), -INT8_C(  47), -INT8_C( 100), -INT8_C(  18), -INT8_C(  31), -INT8_C(  41) },
          {  INT8_C(   0),  INT8_C(  96), -INT8_C(  62), -INT8_C(  35),  INT8_C( 124), -INT8_C(  36),  INT8_C( 126), -INT8_C(  12),
             INT8_C(  82), -INT8_C(  54), -INT8_C( 104), -INT8_C(  25), -INT8_C( 104),  INT8_C( 112), -INT8_C(  12),  INT8_C( 106) },
          { -INT8_C(  64),  INT8_C(  43),  INT8_C(  10),  INT8_C(  10),  INT8_C(  81),  INT8_C(  16),  INT8_C(  83), -INT8_C(  62),
            -INT8_C( 111), -INT8_C( 118), -INT8_C( 108),  INT8_C(  46),  INT8_C( 120),  INT8_C( 117),  INT8_C(   5),  INT8_C( 120) },
          { -INT8_C(  42), -INT8_C(  57),  INT8_C(  86),  INT8_C(  82), -INT8_C(  93), -INT8_C(  44),  INT8_C(  70), -INT8_C(  11),
            -INT8_C(  98), -INT8_C(  33), -INT8_C(  36),  INT8_C(  54),  INT8_C(  79), -INT8_C(  47), -INT8_C(  95),  INT8_C(  15) } },
      { -INT8_C(  46),  INT8_C(  80),  INT8_C(  54), -INT8_C(  97),  INT8_C(  73),  INT8_C(  38),  INT8_C(   6),  INT8_C(  73),
         INT8_C( 113), -INT8_C( 127),  INT8_C(  55), -INT8_C(  47), -INT8_C( 100), -INT8_C(  18), -INT8_C(  31), -INT8_C(  41),
         INT8_C(   0),  INT8_C(  96), -INT8_C(  62), -INT8_C(  35),  INT8_C( 124), -INT8_C(  36),  INT8_C( 126), -INT8_C(  12),
         INT8_C(  82), -INT8_C(  54), -INT8_C( 104), -INT8_C(  25), -INT8_C( 104),  INT8_C( 112), -INT8_C(  12),  INT8_C( 106),
        -INT8_C(  64),  INT8_C(  43),  INT8_C(  10),  INT8_C(  10),  INT8_C(  81),  INT8_C(  16),  INT8_C(  83), -INT8_C(  62),
        -INT8_C( 111), -INT8_C( 118), -INT8_C( 108),  INT8_C(  46),  INT8_C( 120),  INT8_C( 117),  INT8_C(   5),  INT8_C( 120),
        -INT8_C(  42), -INT8_C(  57),  INT8_C(  86),  INT8_C(  82), -INT8_C(  93), -INT8_C(  44),  INT8_C(  70), -INT8_C(  11),
        -INT8_C(  98), -INT8_C(  33), -INT8_C(  36),  INT8_C(  54),  INT8_C(  79), -INT8_C(  47), -INT8_C(  95),  INT8_C(  15) } },
    {
        { { -INT8_C(   4), -INT8_C(  85),  INT8_C(  25),  INT8_C(  77), -INT8_C(  69),  INT8_C( 108),  INT8_C(  16),  INT8_C(  76),
            -INT8_C(   9), -INT8_C(  92),  INT8_C( 122),  INT8_C( 111),  INT8_C(  25),      INT8_MIN, -INT8_C(  24), -INT8_C(  17) },
          {  INT8_C(  71),  INT8_C(  62),  INT8_C(  66), -INT8_C(  21),  INT8_C(  18), -INT8_C( 120), -INT8_C(  32), -INT8_C(  80),
             INT8_C( 103), -INT8_C(  67), -INT8_C(  26), -INT8_C(  74), -INT8_C( 114), -INT8_C( 121), -INT8_C(  58), -INT8_C( 118) },
          {  INT8_C(  50), -INT8_C(  33), -INT8_C(  41), -INT8_C(  19),  INT8_C(  76), -INT8_C(  25),  INT8_C(  58),  INT8_C(  67),
            -INT8_C( 117), -INT8_C(  76), -INT8_C(  78), -INT8_C(  91),  INT8_C(  52), -INT8_C( 102), -INT8_C( 108),  INT8_C( 124) },
          { -INT8_C(  40), -INT8_C(  42),  INT8_C( 103), -INT8_C(  22),  INT8_C(  95),  INT8_C(  71), -INT8_C( 102), -INT8_C(  58),
             INT8_C(   4), -INT8_C( 127),  INT8_C( 125), -INT8_C( 110),  INT8_C(   8),  INT8_C(  67),  INT8_C(  28),  INT8_C(  59) } },
      { -INT8_C(   4), -INT8_C(  85),  INT8_C(  25),  INT8_C(  77), -INT8_C(  69),  INT8_C( 108),  INT8_C(  16),  INT8_C(  76),
        -INT8_C(   9), -INT8_C(  92),  INT8_C( 122),  INT8_C( 111),  INT8_C(  25),      INT8_MIN, -INT8_C(  24), -INT8_C(  17),
         INT8_C(  71),  INT8_C(  62),  INT8_C(  66), -INT8_C(  21),  INT8_C(  18), -INT8_C( 120), -INT8_C(  32), -INT8_C(  80),
         INT8_C( 103), -INT8_C(  67), -INT8_C(  26), -INT8_C(  74), -INT8_C( 114), -INT8_C( 121), -INT8_C(  58), -INT8_C( 118),
         INT8_C(  50), -INT8_C(  33), -INT8_C(  41), -INT8_C(  19),  INT8_C(  76), -INT8_C(  25),  INT8_C(  58),  INT8_C(  67),
        -INT8_C( 117), -INT8_C(  76), -INT8_C(  78), -INT8_C(  91),  INT8_C(  52), -INT8_C( 102), -INT8_C( 108),  INT8_C( 124),
        -INT8_C(  40), -INT8_C(  42),  INT8_C( 103), -INT8_C(  22),  INT8_C(  95),  INT8_C(  71), -INT8_C( 102), -INT8_C(  58),
         INT8_C(   4), -INT8_C( 127),  INT8_C( 125), -INT8_C( 110),  INT8_C(   8),  INT8_C(  67),  INT8_C(  28),  INT8_C(  59) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16x4_t r_ = { { simde_vld1q_s8(test_vec[i].r[0]),
                               simde_vld1q_s8(test_vec[i].r[1]),
                               simde_vld1q_s8(test_vec[i].r[2]),
                               simde_vld1q_s8(test_vec[i].r[3]) } };

    int8_t a_[64];
    simde_vst1q_s8_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t a = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t b = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t c = simde_test_arm_neon_random_i8x16();
    simde_int8x16_t d = simde_test_arm_neon_random_i8x16();
    simde_int8x16x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_i8x16x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    int8_t buf[64];
    simde_vst1q_s8_x4(buf, e);

    simde_test_codegen_write_vi8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s16_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[4][8];
    int16_t a[32];
  } test_vec[] = {
    {
        { { -INT16_C(  3038),  INT16_C( 28200),  INT16_C( 25307),  INT16_C( 26545),  INT16_C( 25623),  INT16_C( 19212), -INT16_C( 24322), -INT16_C( 10297) },
          {  INT16_C( 11895), -INT16_C( 10559),  INT16_C( 23670),  INT16_C( 31388),  INT16_C(  6621), -INT16_C(  6899),  INT16_C( 10588),  INT16_C( 32544) },
          {  INT16_C( 18717), -INT16_C(  1555), -INT16_C( 24661), -INT16_C( 15776),  INT16_C( 27651),  INT16_C(   270), -INT16_C( 10996), -INT16_C( 31784) },
          { -INT16_C( 26108),  INT16_C( 31321), -INT16_C(  2314), -INT16_C( 11276),  INT16_C(   271),  INT16_C( 27832), -INT16_C(  9941),  INT16_C( 18667) } },
      { -INT16_C(  3038),  INT16_C( 28200),  INT16_C( 25307),  INT16_C( 26545),  INT16_C( 25623),  INT16_C( 19212), -INT16_C( 24322), -INT16_C( 10297),
         INT16_C( 11895), -INT16_C( 10559),  INT16_C( 23670),  INT16_C( 31388),  INT16_C(  6621), -INT16_C(  6899),  INT16_C( 10588),  INT16_C( 32544),
         INT16_C( 18717), -INT16_C(  1555), -INT16_C( 24661), -INT16_C( 15776),  INT16_C( 27651),  INT16_C(   270), -INT16_C( 10996), -INT16_C( 31784),
        -INT16_C( 26108),  INT16_C( 31321), -INT16_C(  2314), -INT16_C( 11276),  INT16_C(   271),  INT16_C( 27832), -INT16_C(  9941),  INT16_C( 18667) } },
    {
        { { -INT16_C( 10206), -INT16_C( 12991), -INT16_C( 24201),  INT16_C( 31376), -INT16_C( 25075),  INT16_C(  6780),  INT16_C( 21619),  INT16_C( 30621) },
          { -INT16_C(  2066), -INT16_C(  6927), -INT16_C(  6419), -INT16_C(   841),  INT16_C( 28903),  INT16_C(  4712),  INT16_C( 21321),  INT16_C( 27483) },
          { -INT16_C( 25556), -INT16_C( 23752), -INT16_C( 14274),  INT16_C( 19230), -INT16_C( 26010), -INT16_C(  9627),  INT16_C(  1006), -INT16_C(  8879) },
          {  INT16_C( 17402), -INT16_C(  6207),  INT16_C( 31017),  INT16_C(  4323),  INT16_C( 19689),  INT16_C( 12835),  INT16_C( 32415), -INT16_C( 13411) } },
      { -INT16_C( 10206), -INT16_C( 12991), -INT16_C( 24201),  INT16_C( 31376), -INT16_C( 25075),  INT16_C(  6780),  INT16_C( 21619),  INT16_C( 30621),
        -INT16_C(  2066), -INT16_C(  6927), -INT16_C(  6419), -INT16_C(   841),  INT16_C( 28903),  INT16_C(  4712),  INT16_C( 21321),  INT16_C( 27483),
        -INT16_C( 25556), -INT16_C( 23752), -INT16_C( 14274),  INT16_C( 19230), -INT16_C( 26010), -INT16_C(  9627),  INT16_C(  1006), -INT16_C(  8879),
         INT16_C( 17402), -INT16_C(  6207),  INT16_C( 31017),  INT16_C(  4323),  INT16_C( 19689),  INT16_C( 12835),  INT16_C( 32415), -INT16_C( 13411) } },
    {
        { { -INT16_C( 10982),  INT16_C( 22639), -INT16_C( 29282),  INT16_C(  1188),  INT16_C(  2343),  INT16_C(  5598),  INT16_C( 12300),  INT16_C(  1778) },
          { -INT16_C( 19341), -INT16_C( 25363), -INT16_C( 11987),  INT16_C(  5804), -INT16_C( 12515), -INT16_C( 17336), -INT16_C(  6835),  INT16_C( 26760) },
          { -INT16_C(  2118),  INT16_C( 22720),  INT16_C( 25732), -INT16_C( 21667),  INT16_C( 15214),  INT16_C( 31424), -INT16_C( 19605), -INT16_C(  8575) },
          {  INT16_C( 28263), -INT16_C( 27526),  INT16_C( 10047),  INT16_C( 23722), -INT16_C(  3338),  INT16_C( 17433), -INT16_C( 24105), -INT16_C( 28244) } },
      { -INT16_C( 10982),  INT16_C( 22639), -INT16_C( 29282),  INT16_C(  1188),  INT16_C(  2343),  INT16_C(  5598),  INT16_C( 12300),  INT16_C(  1778),
        -INT16_C( 19341), -INT16_C( 25363), -INT16_C( 11987),  INT16_C(  5804), -INT16_C( 12515), -INT16_C( 17336), -INT16_C(  6835),  INT16_C( 26760),
        -INT16_C(  2118),  INT16_C( 22720),  INT16_C( 25732), -INT16_C( 21667),  INT16_C( 15214),  INT16_C( 31424), -INT16_C( 19605), -INT16_C(  8575),
         INT16_C( 28263), -INT16_C( 27526),  INT16_C( 10047),  INT16_C( 23722), -INT16_C(  3338),  INT16_C( 17433), -INT16_C( 24105), -INT16_C( 28244) } },
    {
        { {  INT16_C( 27800),  INT16_C(  7402),  INT16_C( 18385),  INT16_C( 16327), -INT16_C( 30846), -INT16_C(  4423),  INT16_C( 14906), -INT16_C( 24116) },
          {  INT16_C( 18345), -INT16_C(  6091), -INT16_C(  8338),  INT16_C( 25669),  INT16_C( 24273), -INT16_C( 22360),  INT16_C( 21759), -INT16_C( 26822) },
          {  INT16_C(  9409), -INT16_C( 27981),  INT16_C( 31339), -INT16_C(  4655), -INT16_C( 30207),  INT16_C( 15579), -INT16_C( 22331),  INT16_C( 28381) },
          {  INT16_C(  5103),  INT16_C( 23894), -INT16_C( 25614), -INT16_C( 15167),  INT16_C( 27385), -INT16_C(  1940), -INT16_C( 22850),  INT16_C( 32655) } },
      {  INT16_C( 27800),  INT16_C(  7402),  INT16_C( 18385),  INT16_C( 16327), -INT16_C( 30846), -INT16_C(  4423),  INT16_C( 14906), -INT16_C( 24116),
         INT16_C( 18345), -INT16_C(  6091), -INT16_C(  8338),  INT16_C( 25669),  INT16_C( 24273), -INT16_C( 22360),  INT16_C( 21759), -INT16_C( 26822),
         INT16_C(  9409), -INT16_C( 27981),  INT16_C( 31339), -INT16_C(  4655), -INT16_C( 30207),  INT16_C( 15579), -INT16_C( 22331),  INT16_C( 28381),
         INT16_C(  5103),  INT16_C( 23894), -INT16_C( 25614), -INT16_C( 15167),  INT16_C( 27385), -INT16_C(  1940), -INT16_C( 22850),  INT16_C( 32655) } },
    {
        { {  INT16_C( 17098),  INT16_C( 13585), -INT16_C(  7492), -INT16_C( 16861), -INT16_C(   403),  INT16_C( 13050), -INT16_C( 10330), -INT16_C( 27232) },
          { -INT16_C(  2326), -INT16_C(  8718), -INT16_C( 19310), -INT16_C( 29791),  INT16_C(  3358), -INT16_C(  9084),  INT16_C(  5044),  INT16_C( 32348) },
          {  INT16_C( 27990),  INT16_C(  4788), -INT16_C( 10416), -INT16_C( 16944), -INT16_C( 13611),  INT16_C( 31983), -INT16_C( 28766), -INT16_C( 29679) },
          {  INT16_C(  1157),  INT16_C(  5993),  INT16_C(  2744), -INT16_C( 10589),  INT16_C( 10008), -INT16_C( 13134),  INT16_C(  3642), -INT16_C( 28598) } },
      {  INT16_C( 17098),  INT16_C( 13585), -INT16_C(  7492), -INT16_C( 16861), -INT16_C(   403),  INT16_C( 13050), -INT16_C( 10330), -INT16_C( 27232),
        -INT16_C(  2326), -INT16_C(  8718), -INT16_C( 19310), -INT16_C( 29791),  INT16_C(  3358), -INT16_C(  9084),  INT16_C(  5044),  INT16_C( 32348),
         INT16_C( 27990),  INT16_C(  4788), -INT16_C( 10416), -INT16_C( 16944), -INT16_C( 13611),  INT16_C( 31983), -INT16_C( 28766), -INT16_C( 29679),
         INT16_C(  1157),  INT16_C(  5993),  INT16_C(  2744), -INT16_C( 10589),  INT16_C( 10008), -INT16_C( 13134),  INT16_C(  3642), -INT16_C( 28598) } },
    {
        { { -INT16_C(   388), -INT16_C( 13149),  INT16_C( 29653), -INT16_C( 21623),  INT16_C( 30782), -INT16_C(  8153),  INT16_C( 14343), -INT16_C( 29588) },
          { -INT16_C( 10692), -INT16_C(  2908),  INT16_C( 18400), -INT16_C(  1846),  INT16_C( 32110), -INT16_C( 22332),  INT16_C(  3979),  INT16_C(  1849) },
          { -INT16_C(  9203), -INT16_C(  7213),  INT16_C( 23631), -INT16_C( 29298), -INT16_C( 18988), -INT16_C(  9363), -INT16_C(  9491),  INT16_C( 10856) },
          {  INT16_C(  3248), -INT16_C( 28642), -INT16_C(  5805), -INT16_C( 15991),  INT16_C( 19814), -INT16_C(  3735), -INT16_C( 23972),  INT16_C( 27385) } },
      { -INT16_C(   388), -INT16_C( 13149),  INT16_C( 29653), -INT16_C( 21623),  INT16_C( 30782), -INT16_C(  8153),  INT16_C( 14343), -INT16_C( 29588),
        -INT16_C( 10692), -INT16_C(  2908),  INT16_C( 18400), -INT16_C(  1846),  INT16_C( 32110), -INT16_C( 22332),  INT16_C(  3979),  INT16_C(  1849),
        -INT16_C(  9203), -INT16_C(  7213),  INT16_C( 23631), -INT16_C( 29298), -INT16_C( 18988), -INT16_C(  9363), -INT16_C(  9491),  INT16_C( 10856),
         INT16_C(  3248), -INT16_C( 28642), -INT16_C(  5805), -INT16_C( 15991),  INT16_C( 19814), -INT16_C(  3735), -INT16_C( 23972),  INT16_C( 27385) } },
    {
        { { -INT16_C( 13186), -INT16_C( 12723), -INT16_C(  9431), -INT16_C(   677), -INT16_C( 13936),  INT16_C( 32217),  INT16_C( 16803),  INT16_C( 21415) },
          { -INT16_C( 14771), -INT16_C( 24349),  INT16_C( 27823),  INT16_C(  5473), -INT16_C( 13638),  INT16_C(  5638), -INT16_C(   147), -INT16_C(  5248) },
          { -INT16_C( 12852), -INT16_C(  2631),  INT16_C(  5544),  INT16_C( 14578), -INT16_C( 13346), -INT16_C( 32330),  INT16_C( 23820),  INT16_C( 22996) },
          { -INT16_C( 18653), -INT16_C( 11527),  INT16_C( 23076), -INT16_C(  8473), -INT16_C(  4571), -INT16_C( 27916),  INT16_C( 30189), -INT16_C( 18051) } },
      { -INT16_C( 13186), -INT16_C( 12723), -INT16_C(  9431), -INT16_C(   677), -INT16_C( 13936),  INT16_C( 32217),  INT16_C( 16803),  INT16_C( 21415),
        -INT16_C( 14771), -INT16_C( 24349),  INT16_C( 27823),  INT16_C(  5473), -INT16_C( 13638),  INT16_C(  5638), -INT16_C(   147), -INT16_C(  5248),
        -INT16_C( 12852), -INT16_C(  2631),  INT16_C(  5544),  INT16_C( 14578), -INT16_C( 13346), -INT16_C( 32330),  INT16_C( 23820),  INT16_C( 22996),
        -INT16_C( 18653), -INT16_C( 11527),  INT16_C( 23076), -INT16_C(  8473), -INT16_C(  4571), -INT16_C( 27916),  INT16_C( 30189), -INT16_C( 18051) } },
    {
        { {  INT16_C( 14146), -INT16_C(  5202), -INT16_C( 24244),  INT16_C( 10787), -INT16_C(  9876),  INT16_C( 31147),  INT16_C( 32567),  INT16_C( 23250) },
          { -INT16_C( 13258),  INT16_C( 23085),  INT16_C(  5158),  INT16_C( 19256),  INT16_C( 11522), -INT16_C(  3875),  INT16_C( 23458), -INT16_C(  6999) },
          {  INT16_C( 22674), -INT16_C(  8497), -INT16_C(  3079),  INT16_C( 25864), -INT16_C( 19508),  INT16_C(   990), -INT16_C( 20174),  INT16_C( 26718) },
          { -INT16_C( 29827), -INT16_C( 23613), -INT16_C(  1121), -INT16_C( 23825), -INT16_C( 13272), -INT16_C( 13678),  INT16_C( 15143), -INT16_C( 18001) } },
      {  INT16_C( 14146), -INT16_C(  5202), -INT16_C( 24244),  INT16_C( 10787), -INT16_C(  9876),  INT16_C( 31147),  INT16_C( 32567),  INT16_C( 23250),
        -INT16_C( 13258),  INT16_C( 23085),  INT16_C(  5158),  INT16_C( 19256),  INT16_C( 11522), -INT16_C(  3875),  INT16_C( 23458), -INT16_C(  6999),
         INT16_C( 22674), -INT16_C(  8497), -INT16_C(  3079),  INT16_C( 25864), -INT16_C( 19508),  INT16_C(   990), -INT16_C( 20174),  INT16_C( 26718),
        -INT16_C( 29827), -INT16_C( 23613), -INT16_C(  1121), -INT16_C( 23825), -INT16_C( 13272), -INT16_C( 13678),  INT16_C( 15143), -INT16_C( 18001) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8x4_t r_ = { { simde_vld1q_s16(test_vec[i].r[0]),
                               simde_vld1q_s16(test_vec[i].r[1]),
                               simde_vld1q_s16(test_vec[i].r[2]),
                               simde_vld1q_s16(test_vec[i].r[3]) } };

    int16_t a_[32];
    simde_vst1q_s16_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t a = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t b = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t c = simde_test_arm_neon_random_i16x8();
    simde_int16x8_t d = simde_test_arm_neon_random_i16x8();
    simde_int16x8x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_i16x8x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    int16_t buf[32];
    simde_vst1q_s16_x4(buf, e);

    simde_test_codegen_write_vi16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[4][4];
    int32_t a[16];
  } test_vec[] = {
    {
        { { -INT32_C(  1936228717),  INT32_C(  1056087921), -INT32_C(  2076061614), -INT32_C(    17981567) },
          { -INT32_C(   895307734), -INT32_C(   731082325), -INT32_C(  2053177763), -INT32_C(   851555015) },
          {  INT32_C(  1029297868), -INT32_C(   931443851), -INT32_C(  1655915236), -INT32_C(  2019804836) },
          { -INT32_C(  1789837591),  INT32_C(   745127375), -INT32_C(   189724741),  INT32_C(   566358101) } },
      { -INT32_C(  1936228717),  INT32_C(  1056087921), -INT32_C(  2076061614), -INT32_C(    17981567), -INT32_C(   895307734), -INT32_C(   731082325), -INT32_C(  2053177763), -INT32_C(   851555015),
         INT32_C(  1029297868), -INT32_C(   931443851), -INT32_C(  1655915236), -INT32_C(  2019804836), -INT32_C(  1789837591),  INT32_C(   745127375), -INT32_C(   189724741),  INT32_C(   566358101) } },
    {
        { {  INT32_C(   996023238), -INT32_C(  2113676698), -INT32_C(   215986025),  INT32_C(  1937423497) },
          { -INT32_C(   922170374),  INT32_C(  1140158856), -INT32_C(   851925128),  INT32_C(  1575942551) },
          {  INT32_C(  2073578772), -INT32_C(  1090675673),  INT32_C(  1974541804), -INT32_C(   739758887) },
          { -INT32_C(  2137198345), -INT32_C(   624717215), -INT32_C(   794297543),  INT32_C(   153982709) } },
      {  INT32_C(   996023238), -INT32_C(  2113676698), -INT32_C(   215986025),  INT32_C(  1937423497), -INT32_C(   922170374),  INT32_C(  1140158856), -INT32_C(   851925128),  INT32_C(  1575942551),
         INT32_C(  2073578772), -INT32_C(  1090675673),  INT32_C(  1974541804), -INT32_C(   739758887), -INT32_C(  2137198345), -INT32_C(   624717215), -INT32_C(   794297543),  INT32_C(   153982709) } },
    {
        { {  INT32_C(   176473571),  INT32_C(  1304986209),  INT32_C(  2042853791), -INT32_C(  1655919707) },
          { -INT32_C(    48371300), -INT32_C(  1260920709), -INT32_C(   779845668), -INT32_C(   119885547) },
          { -INT32_C(   670933130), -INT32_C(  2145006879), -INT32_C(   369498045),  INT32_C(   814106260) },
          { -INT32_C(  1439849681),  INT32_C(  1599997315), -INT32_C(  1724849532),  INT32_C(   160500627) } },
      {  INT32_C(   176473571),  INT32_C(  1304986209),  INT32_C(  2042853791), -INT32_C(  1655919707), -INT32_C(    48371300), -INT32_C(  1260920709), -INT32_C(   779845668), -INT32_C(   119885547),
        -INT32_C(   670933130), -INT32_C(  2145006879), -INT32_C(   369498045),  INT32_C(   814106260), -INT32_C(  1439849681),  INT32_C(  1599997315), -INT32_C(  1724849532),  INT32_C(   160500627) } },
    {
        { {  INT32_C(  1273074538), -INT32_C(  1597307043), -INT32_C(  2088122897),  INT32_C(   984813323) },
          {  INT32_C(   920969650),  INT32_C(  1788166886), -INT32_C(  1224489436),  INT32_C(  1002476753) },
          { -INT32_C(  2071551449), -INT32_C(  1742450263),  INT32_C(   555527702),  INT32_C(  1885065149) },
          { -INT32_C(  1767489616), -INT32_C(  1526711423), -INT32_C(   765721855), -INT32_C(  1106436713) } },
      {  INT32_C(  1273074538), -INT32_C(  1597307043), -INT32_C(  2088122897),  INT32_C(   984813323),  INT32_C(   920969650),  INT32_C(  1788166886), -INT32_C(  1224489436),  INT32_C(  1002476753),
        -INT32_C(  2071551449), -INT32_C(  1742450263),  INT32_C(   555527702),  INT32_C(  1885065149), -INT32_C(  1767489616), -INT32_C(  1526711423), -INT32_C(   765721855), -INT32_C(  1106436713) } },
    {
        { {  INT32_C(  1749193663), -INT32_C(    83859483), -INT32_C(   769844203), -INT32_C(  1673365268) },
          {  INT32_C(   959703224),  INT32_C(   635384612), -INT32_C(   822592713),  INT32_C(   395117912) },
          {  INT32_C(  2122305433),  INT32_C(  1266253878), -INT32_C(  2011261284), -INT32_C(   953851889) },
          {  INT32_C(  1828739145), -INT32_C(  1030561909),  INT32_C(  1938917915),  INT32_C(   696983184) } },
      {  INT32_C(  1749193663), -INT32_C(    83859483), -INT32_C(   769844203), -INT32_C(  1673365268),  INT32_C(   959703224),  INT32_C(   635384612), -INT32_C(   822592713),  INT32_C(   395117912),
         INT32_C(  2122305433),  INT32_C(  1266253878), -INT32_C(  2011261284), -INT32_C(   953851889),  INT32_C(  1828739145), -INT32_C(  1030561909),  INT32_C(  1938917915),  INT32_C(   696983184) } },
    {
        { {  INT32_C(   614927085),  INT32_C(   661594250), -INT32_C(   961573449),  INT32_C(   932041966) },
          { -INT32_C(  1197175508), -INT32_C(  2005256595),  INT32_C(  1375407041),  INT32_C(   393905705) },
          {  INT32_C(   456860049), -INT32_C(   129848767),  INT32_C(   650048056), -INT32_C(   211989562) },
          {  INT32_C(  1185612249), -INT32_C(   120707785),  INT32_C(  1514785073), -INT32_C(   512638128) } },
      {  INT32_C(   614927085),  INT32_C(   661594250), -INT32_C(   961573449),  INT32_C(   932041966), -INT32_C(  1197175508), -INT32_C(  2005256595),  INT32_C(  1375407041),  INT32_C(   393905705),
         INT32_C(   456860049), -INT32_C(   129848767),  INT32_C(   650048056), -INT32_C(   211989562),  INT32_C(  1185612249), -INT32_C(   120707785),  INT32_C(  1514785073), -INT32_C(   512638128) } },
    {
        { {  INT32_C(   654093540), -INT32_C(  1893843113), -INT32_C(   139076303),  INT32_C(    32117288) },
          {  INT32_C(  1246205203), -INT32_C(   331147845),  INT32_C(   793152735),  INT32_C(   873510992) },
          { -INT32_C(  1151726492),  INT32_C(  2085255499),  INT32_C(  2121596758),  INT32_C(   612392465) },
          { -INT32_C(  1351628812), -INT32_C(  1130646819), -INT32_C(  1897144002), -INT32_C(    20710503) } },
      {  INT32_C(   654093540), -INT32_C(  1893843113), -INT32_C(   139076303),  INT32_C(    32117288),  INT32_C(  1246205203), -INT32_C(   331147845),  INT32_C(   793152735),  INT32_C(   873510992),
        -INT32_C(  1151726492),  INT32_C(  2085255499),  INT32_C(  2121596758),  INT32_C(   612392465), -INT32_C(  1351628812), -INT32_C(  1130646819), -INT32_C(  1897144002), -INT32_C(    20710503) } },
    {
        { {  INT32_C(  1404640519), -INT32_C(   321977194),  INT32_C(   359351043), -INT32_C(  1774589022) },
          { -INT32_C(  1891260238), -INT32_C(  1723080614),  INT32_C(  1529296577),  INT32_C(   962193969) },
          { -INT32_C(  1634987512),  INT32_C(   445340438),  INT32_C(  1093662367), -INT32_C(  1814599455) },
          {  INT32_C(  1797463057), -INT32_C(  1123782916), -INT32_C(   703058779),  INT32_C(   504328470) } },
      {  INT32_C(  1404640519), -INT32_C(   321977194),  INT32_C(   359351043), -INT32_C(  1774589022), -INT32_C(  1891260238), -INT32_C(  1723080614),  INT32_C(  1529296577),  INT32_C(   962193969),
        -INT32_C(  1634987512),  INT32_C(   445340438),  INT32_C(  1093662367), -INT32_C(  1814599455),  INT32_C(  1797463057), -INT32_C(  1123782916), -INT32_C(   703058779),  INT32_C(   504328470) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4x4_t r_ = { { simde_vld1q_s32(test_vec[i].r[0]),
                               simde_vld1q_s32(test_vec[i].r[1]),
                               simde_vld1q_s32(test_vec[i].r[2]),
                               simde_vld1q_s32(test_vec[i].r[3]) } };

    int32_t a_[16];
    simde_vst1q_s32_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t a = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t b = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t c = simde_test_arm_neon_random_i32x4();
    simde_int32x4_t d = simde_test_arm_neon_random_i32x4();
    simde_int32x4x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_i32x4x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    int32_t buf[16];
    simde_vst1q_s32_x4(buf, e);

    simde_test_codegen_write_vi32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_s64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r[4][2];
    int64_t a[8];
  } test_vec[] = {
    {
        { { -INT64_C( 7587359243922203772),  INT64_C( 6751650433356784446) },
          { -INT64_C( 1620225745646725686), -INT64_C( 7985217434275570439) },
          {  INT64_C( 8212278956811676522),  INT64_C( 5074785455737720516) },
          { -INT64_C(  340707856987966184),  INT64_C( 4524773829981701164) } },
      { -INT64_C( 7587359243922203772),  INT64_C( 6751650433356784446), -INT64_C( 1620225745646725686), -INT64_C( 7985217434275570439),
         INT64_C( 8212278956811676522),  INT64_C( 5074785455737720516), -INT64_C(  340707856987966184),  INT64_C( 4524773829981701164) } },
    {
        { { -INT64_C( 7221355051344726236), -INT64_C( 5609206282383042459) },
          { -INT64_C( 1059379705422138034), -INT64_C( 5446552274779613352) },
          {  INT64_C(  387260780414437868),  INT64_C( 8176302869321288491) },
          {  INT64_C( 3673546250696951365),  INT64_C(  552191352224163173) } },
      { -INT64_C( 7221355051344726236), -INT64_C( 5609206282383042459), -INT64_C( 1059379705422138034), -INT64_C( 5446552274779613352),
         INT64_C(  387260780414437868),  INT64_C( 8176302869321288491),  INT64_C( 3673546250696951365),  INT64_C(  552191352224163173) } },
    {
        { { -INT64_C( 5587511901970254640), -INT64_C( 5563089661754647242) },
          {  INT64_C(   36793624674733430),  INT64_C( 8574746655498559452) },
          {  INT64_C( 3137703776386206290),  INT64_C( 7554877375872565945) },
          {  INT64_C( 2844087260506789085),  INT64_C( 6716588930086432025) } },
      { -INT64_C( 5587511901970254640), -INT64_C( 5563089661754647242),  INT64_C(   36793624674733430),  INT64_C( 8574746655498559452),
         INT64_C( 3137703776386206290),  INT64_C( 7554877375872565945),  INT64_C( 2844087260506789085),  INT64_C( 6716588930086432025) } },
    {
        { {  INT64_C( 3605625705850084840), -INT64_C( 4963757481209065789) },
          {  INT64_C( 2969749085465335236),  INT64_C( 6665362027892528408) },
          {  INT64_C( 4316492949278602812),  INT64_C( 3705352466291769298) },
          {  INT64_C( 7141716476213501923),  INT64_C( 7034067520315655630) } },
      {  INT64_C( 3605625705850084840), -INT64_C( 4963757481209065789),  INT64_C( 2969749085465335236),  INT64_C( 6665362027892528408),
         INT64_C( 4316492949278602812),  INT64_C( 3705352466291769298),  INT64_C( 7141716476213501923),  INT64_C( 7034067520315655630) } },
    {
        { { -INT64_C( 1337289696520775490),  INT64_C( 5971784580663763261) },
          {  INT64_C( 7662982092711863209), -INT64_C( 6562788202939359386) },
          {  INT64_C( 4479755619265020450),  INT64_C( 9038104134752651691) },
          {  INT64_C( 8860208931980554990),  INT64_C( 1023427538657321384) } },
      { -INT64_C( 1337289696520775490),  INT64_C( 5971784580663763261),  INT64_C( 7662982092711863209), -INT64_C( 6562788202939359386),
         INT64_C( 4479755619265020450),  INT64_C( 9038104134752651691),  INT64_C( 8860208931980554990),  INT64_C( 1023427538657321384) } },
    {
        { {  INT64_C(  230378854400396788), -INT64_C( 2913112175757353663) },
          {  INT64_C( 8488255937031832381), -INT64_C( 5191743531432750600) },
          { -INT64_C(  458840806809452731), -INT64_C( 8665875339453480965) },
          {  INT64_C( 7919198918600629923),  INT64_C( 7561619787648002678) } },
      {  INT64_C(  230378854400396788), -INT64_C( 2913112175757353663),  INT64_C( 8488255937031832381), -INT64_C( 5191743531432750600),
        -INT64_C(  458840806809452731), -INT64_C( 8665875339453480965),  INT64_C( 7919198918600629923),  INT64_C( 7561619787648002678) } },
    {
        { {  INT64_C( 8445839720126454916), -INT64_C( 8775520181752806555) },
          {  INT64_C( 3104912765428895796),  INT64_C( 3626054855436888263) },
          {  INT64_C( 7197213992634177521), -INT64_C( 8840765828378706970) },
          { -INT64_C( 1496809008778033574), -INT64_C( 1834047013502214227) } },
      {  INT64_C( 8445839720126454916), -INT64_C( 8775520181752806555),  INT64_C( 3104912765428895796),  INT64_C( 3626054855436888263),
         INT64_C( 7197213992634177521), -INT64_C( 8840765828378706970), -INT64_C( 1496809008778033574), -INT64_C( 1834047013502214227) } },
    {
        { { -INT64_C( 8944092108469110146), -INT64_C( 7546735286549679250) },
          {  INT64_C( 7201784351542375138),  INT64_C( 7735859168682100352) },
          {  INT64_C( 5649423650787994949),  INT64_C( 3571162429139038907) },
          { -INT64_C( 7647912519495371325),  INT64_C( 3118292933704063982) } },
      { -INT64_C( 8944092108469110146), -INT64_C( 7546735286549679250),  INT64_C( 7201784351542375138),  INT64_C( 7735859168682100352),
         INT64_C( 5649423650787994949),  INT64_C( 3571162429139038907), -INT64_C( 7647912519495371325),  INT64_C( 3118292933704063982) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2x4_t r_ = { { simde_vld1q_s64(test_vec[i].r[0]),
                               simde_vld1q_s64(test_vec[i].r[1]),
                               simde_vld1q_s64(test_vec[i].r[2]),
                               simde_vld1q_s64(test_vec[i].r[3]) } };

    int64_t a_[8];
    simde_vst1q_s64_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t a = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t b = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t c = simde_test_arm_neon_random_i64x2();
    simde_int64x2_t d = simde_test_arm_neon_random_i64x2();
    simde_int64x2x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_i64x2x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    int64_t buf[8];
    simde_vst1q_s64_x4(buf, e);

    simde_test_codegen_write_vi64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u8_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[4][16];
    uint8_t a[64];
  } test_vec[] = {
    {
        { { UINT8_C( 19), UINT8_C( 46), UINT8_C( 13), UINT8_C(244), UINT8_C(246), UINT8_C(115), UINT8_C( 66), UINT8_C(177),
            UINT8_C( 38), UINT8_C( 80), UINT8_C(169), UINT8_C(116), UINT8_C(161), UINT8_C( 56), UINT8_C(165), UINT8_C(101) },
          { UINT8_C(109), UINT8_C(220), UINT8_C(223), UINT8_C(131), UINT8_C(  4), UINT8_C(188), UINT8_C( 24), UINT8_C(242),
            UINT8_C( 88), UINT8_C( 35), UINT8_C(205), UINT8_C( 62), UINT8_C(137), UINT8_C( 20), UINT8_C(105), UINT8_C(156) },
          { UINT8_C( 66), UINT8_C(118), UINT8_C(144), UINT8_C( 57), UINT8_C(234), UINT8_C(211), UINT8_C(234), UINT8_C( 16),
            UINT8_C( 35), UINT8_C(148), UINT8_C(132), UINT8_C(196), UINT8_C(204), UINT8_C( 42), UINT8_C( 41), UINT8_C( 58) },
          { UINT8_C(  6), UINT8_C(  8), UINT8_C(189), UINT8_C( 11), UINT8_C(197), UINT8_C(213), UINT8_C(253), UINT8_C( 29),
            UINT8_C(248), UINT8_C(203), UINT8_C( 91), UINT8_C(129), UINT8_C(223), UINT8_C(196), UINT8_C( 30), UINT8_C( 33) } },
      { UINT8_C( 19), UINT8_C( 46), UINT8_C( 13), UINT8_C(244), UINT8_C(246), UINT8_C(115), UINT8_C( 66), UINT8_C(177),
        UINT8_C( 38), UINT8_C( 80), UINT8_C(169), UINT8_C(116), UINT8_C(161), UINT8_C( 56), UINT8_C(165), UINT8_C(101),
        UINT8_C(109), UINT8_C(220), UINT8_C(223), UINT8_C(131), UINT8_C(  4), UINT8_C(188), UINT8_C( 24), UINT8_C(242),
        UINT8_C( 88), UINT8_C( 35), UINT8_C(205), UINT8_C( 62), UINT8_C(137), UINT8_C( 20), UINT8_C(105), UINT8_C(156),
        UINT8_C( 66), UINT8_C(118), UINT8_C(144), UINT8_C( 57), UINT8_C(234), UINT8_C(211), UINT8_C(234), UINT8_C( 16),
        UINT8_C( 35), UINT8_C(148), UINT8_C(132), UINT8_C(196), UINT8_C(204), UINT8_C( 42), UINT8_C( 41), UINT8_C( 58),
        UINT8_C(  6), UINT8_C(  8), UINT8_C(189), UINT8_C( 11), UINT8_C(197), UINT8_C(213), UINT8_C(253), UINT8_C( 29),
        UINT8_C(248), UINT8_C(203), UINT8_C( 91), UINT8_C(129), UINT8_C(223), UINT8_C(196), UINT8_C( 30), UINT8_C( 33) } },
    {
        { { UINT8_C( 58), UINT8_C(174), UINT8_C( 90), UINT8_C( 36), UINT8_C(129), UINT8_C( 69), UINT8_C( 52), UINT8_C(164),
            UINT8_C(217), UINT8_C(185), UINT8_C(105), UINT8_C(165), UINT8_C(227), UINT8_C(146), UINT8_C(223), UINT8_C(233) },
          { UINT8_C(155), UINT8_C(156), UINT8_C(244), UINT8_C( 96), UINT8_C(114), UINT8_C(242), UINT8_C(125), UINT8_C(106),
            UINT8_C(189), UINT8_C(216), UINT8_C(236), UINT8_C(156), UINT8_C(156), UINT8_C( 10), UINT8_C(189), UINT8_C(214) },
          { UINT8_C(184), UINT8_C( 24), UINT8_C(251), UINT8_C( 58), UINT8_C( 93), UINT8_C( 47), UINT8_C(222), UINT8_C( 54),
            UINT8_C(232), UINT8_C( 71), UINT8_C(219), UINT8_C(203), UINT8_C(218), UINT8_C(187), UINT8_C(181), UINT8_C(117) },
          { UINT8_C( 87), UINT8_C(169), UINT8_C(213), UINT8_C(201), UINT8_C(155), UINT8_C( 82), UINT8_C( 52), UINT8_C( 88),
            UINT8_C( 42), UINT8_C( 32), UINT8_C(244), UINT8_C(198), UINT8_C( 42), UINT8_C(178), UINT8_C(156), UINT8_C(226) } },
      { UINT8_C( 58), UINT8_C(174), UINT8_C( 90), UINT8_C( 36), UINT8_C(129), UINT8_C( 69), UINT8_C( 52), UINT8_C(164),
        UINT8_C(217), UINT8_C(185), UINT8_C(105), UINT8_C(165), UINT8_C(227), UINT8_C(146), UINT8_C(223), UINT8_C(233),
        UINT8_C(155), UINT8_C(156), UINT8_C(244), UINT8_C( 96), UINT8_C(114), UINT8_C(242), UINT8_C(125), UINT8_C(106),
        UINT8_C(189), UINT8_C(216), UINT8_C(236), UINT8_C(156), UINT8_C(156), UINT8_C( 10), UINT8_C(189), UINT8_C(214),
        UINT8_C(184), UINT8_C( 24), UINT8_C(251), UINT8_C( 58), UINT8_C( 93), UINT8_C( 47), UINT8_C(222), UINT8_C( 54),
        UINT8_C(232), UINT8_C( 71), UINT8_C(219), UINT8_C(203), UINT8_C(218), UINT8_C(187), UINT8_C(181), UINT8_C(117),
        UINT8_C( 87), UINT8_C(169), UINT8_C(213), UINT8_C(201), UINT8_C(155), UINT8_C( 82), UINT8_C( 52), UINT8_C( 88),
        UINT8_C( 42), UINT8_C( 32), UINT8_C(244), UINT8_C(198), UINT8_C( 42), UINT8_C(178), UINT8_C(156), UINT8_C(226) } },
    {
        { { UINT8_C(202), UINT8_C(151), UINT8_C( 28), UINT8_C( 39), UINT8_C(199), UINT8_C(251), UINT8_C( 93), UINT8_C(175),
            UINT8_C( 66), UINT8_C( 56), UINT8_C(123), UINT8_C( 28), UINT8_C(243), UINT8_C( 48), UINT8_C(145), UINT8_C( 75) },
          { UINT8_C(217), UINT8_C(102), UINT8_C( 20), UINT8_C(117), UINT8_C(184), UINT8_C( 72), UINT8_C(205), UINT8_C(226),
            UINT8_C(104), UINT8_C(194), UINT8_C(168), UINT8_C(146), UINT8_C(116), UINT8_C( 69), UINT8_C(117), UINT8_C( 62) },
          { UINT8_C(220), UINT8_C(145), UINT8_C(101), UINT8_C(163), UINT8_C(140), UINT8_C(194), UINT8_C( 83), UINT8_C(207),
            UINT8_C(250), UINT8_C(206), UINT8_C(235), UINT8_C(238), UINT8_C(254), UINT8_C(125), UINT8_C( 57), UINT8_C(215) },
          { UINT8_C(227), UINT8_C( 77), UINT8_C( 76), UINT8_C(156), UINT8_C(150), UINT8_C( 26), UINT8_C(126), UINT8_C(254),
            UINT8_C(220), UINT8_C( 39), UINT8_C(145), UINT8_C( 80), UINT8_C(108), UINT8_C(  6), UINT8_C(142), UINT8_C( 72) } },
      { UINT8_C(202), UINT8_C(151), UINT8_C( 28), UINT8_C( 39), UINT8_C(199), UINT8_C(251), UINT8_C( 93), UINT8_C(175),
        UINT8_C( 66), UINT8_C( 56), UINT8_C(123), UINT8_C( 28), UINT8_C(243), UINT8_C( 48), UINT8_C(145), UINT8_C( 75),
        UINT8_C(217), UINT8_C(102), UINT8_C( 20), UINT8_C(117), UINT8_C(184), UINT8_C( 72), UINT8_C(205), UINT8_C(226),
        UINT8_C(104), UINT8_C(194), UINT8_C(168), UINT8_C(146), UINT8_C(116), UINT8_C( 69), UINT8_C(117), UINT8_C( 62),
        UINT8_C(220), UINT8_C(145), UINT8_C(101), UINT8_C(163), UINT8_C(140), UINT8_C(194), UINT8_C( 83), UINT8_C(207),
        UINT8_C(250), UINT8_C(206), UINT8_C(235), UINT8_C(238), UINT8_C(254), UINT8_C(125), UINT8_C( 57), UINT8_C(215),
        UINT8_C(227), UINT8_C( 77), UINT8_C( 76), UINT8_C(156), UINT8_C(150), UINT8_C( 26), UINT8_C(126), UINT8_C(254),
        UINT8_C(220), UINT8_C( 39), UINT8_C(145), UINT8_C( 80), UINT8_C(108), UINT8_C(  6), UINT8_C(142), UINT8_C( 72) } },
    {
        { { UINT8_C(151), UINT8_C(243), UINT8_C(236), UINT8_C( 36), UINT8_C(181), UINT8_C( 63), UINT8_C(243), UINT8_C(175),
            UINT8_C( 13), UINT8_C(222), UINT8_C(157), UINT8_C( 11), UINT8_C( 91), UINT8_C(214), UINT8_C(226), UINT8_C( 63) },
          { UINT8_C( 36), UINT8_C( 47), UINT8_C(219), UINT8_C(186), UINT8_C( 73), UINT8_C( 89), UINT8_C(184), UINT8_C( 37),
            UINT8_C(128), UINT8_C( 73), UINT8_C(117), UINT8_C(236), UINT8_C( 79), UINT8_C(  3), UINT8_C( 53), UINT8_C(231) },
          { UINT8_C(246), UINT8_C( 33), UINT8_C( 11), UINT8_C(171), UINT8_C( 96), UINT8_C(254), UINT8_C( 90), UINT8_C(109),
            UINT8_C(220), UINT8_C(248), UINT8_C(120), UINT8_C( 56), UINT8_C(206), UINT8_C( 90), UINT8_C(119), UINT8_C(242) },
          { UINT8_C(137), UINT8_C( 82), UINT8_C(172), UINT8_C(210), UINT8_C(171), UINT8_C(101), UINT8_C(247), UINT8_C( 44),
            UINT8_C(174), UINT8_C(108), UINT8_C( 24), UINT8_C(254), UINT8_C(111), UINT8_C( 77), UINT8_C(229), UINT8_C(101) } },
      { UINT8_C(151), UINT8_C(243), UINT8_C(236), UINT8_C( 36), UINT8_C(181), UINT8_C( 63), UINT8_C(243), UINT8_C(175),
        UINT8_C( 13), UINT8_C(222), UINT8_C(157), UINT8_C( 11), UINT8_C( 91), UINT8_C(214), UINT8_C(226), UINT8_C( 63),
        UINT8_C( 36), UINT8_C( 47), UINT8_C(219), UINT8_C(186), UINT8_C( 73), UINT8_C( 89), UINT8_C(184), UINT8_C( 37),
        UINT8_C(128), UINT8_C( 73), UINT8_C(117), UINT8_C(236), UINT8_C( 79), UINT8_C(  3), UINT8_C( 53), UINT8_C(231),
        UINT8_C(246), UINT8_C( 33), UINT8_C( 11), UINT8_C(171), UINT8_C( 96), UINT8_C(254), UINT8_C( 90), UINT8_C(109),
        UINT8_C(220), UINT8_C(248), UINT8_C(120), UINT8_C( 56), UINT8_C(206), UINT8_C( 90), UINT8_C(119), UINT8_C(242),
        UINT8_C(137), UINT8_C( 82), UINT8_C(172), UINT8_C(210), UINT8_C(171), UINT8_C(101), UINT8_C(247), UINT8_C( 44),
        UINT8_C(174), UINT8_C(108), UINT8_C( 24), UINT8_C(254), UINT8_C(111), UINT8_C( 77), UINT8_C(229), UINT8_C(101) } },
    {
        { { UINT8_C(110), UINT8_C(240), UINT8_C( 16), UINT8_C(206), UINT8_C(238), UINT8_C(107), UINT8_C( 59), UINT8_C(202),
            UINT8_C( 99), UINT8_C(179), UINT8_C(  2), UINT8_C( 49), UINT8_C( 14), UINT8_C(121), UINT8_C( 36), UINT8_C(151) },
          { UINT8_C(203), UINT8_C(208), UINT8_C(106), UINT8_C(119), UINT8_C( 53), UINT8_C( 97), UINT8_C(163), UINT8_C(228),
            UINT8_C(206), UINT8_C(187), UINT8_C(226), UINT8_C( 61), UINT8_C(  9), UINT8_C(199), UINT8_C(163), UINT8_C(119) },
          { UINT8_C(183), UINT8_C(179), UINT8_C( 70), UINT8_C(165), UINT8_C( 30), UINT8_C(129), UINT8_C(111), UINT8_C(129),
            UINT8_C( 53), UINT8_C(114), UINT8_C(179), UINT8_C( 67), UINT8_C(235), UINT8_C(215), UINT8_C(218), UINT8_C(183) },
          { UINT8_C(167), UINT8_C( 68), UINT8_C( 46), UINT8_C(221), UINT8_C(166), UINT8_C(209), UINT8_C(193), UINT8_C(116),
            UINT8_C(140), UINT8_C(163), UINT8_C(177), UINT8_C(149), UINT8_C(106), UINT8_C( 84), UINT8_C( 13), UINT8_C( 33) } },
      { UINT8_C(110), UINT8_C(240), UINT8_C( 16), UINT8_C(206), UINT8_C(238), UINT8_C(107), UINT8_C( 59), UINT8_C(202),
        UINT8_C( 99), UINT8_C(179), UINT8_C(  2), UINT8_C( 49), UINT8_C( 14), UINT8_C(121), UINT8_C( 36), UINT8_C(151),
        UINT8_C(203), UINT8_C(208), UINT8_C(106), UINT8_C(119), UINT8_C( 53), UINT8_C( 97), UINT8_C(163), UINT8_C(228),
        UINT8_C(206), UINT8_C(187), UINT8_C(226), UINT8_C( 61), UINT8_C(  9), UINT8_C(199), UINT8_C(163), UINT8_C(119),
        UINT8_C(183), UINT8_C(179), UINT8_C( 70), UINT8_C(165), UINT8_C( 30), UINT8_C(129), UINT8_C(111), UINT8_C(129),
        UINT8_C( 53), UINT8_C(114), UINT8_C(179), UINT8_C( 67), UINT8_C(235), UINT8_C(215), UINT8_C(218), UINT8_C(183),
        UINT8_C(167), UINT8_C( 68), UINT8_C( 46), UINT8_C(221), UINT8_C(166), UINT8_C(209), UINT8_C(193), UINT8_C(116),
        UINT8_C(140), UINT8_C(163), UINT8_C(177), UINT8_C(149), UINT8_C(106), UINT8_C( 84), UINT8_C( 13), UINT8_C( 33) } },
    {
        { { UINT8_C(  8), UINT8_C( 83), UINT8_C(198), UINT8_C( 38), UINT8_C(212), UINT8_C( 53), UINT8_C(168), UINT8_C(  9),
            UINT8_C(167), UINT8_C( 91), UINT8_C( 76), UINT8_C(147), UINT8_C( 50), UINT8_C( 39), UINT8_C( 74), UINT8_C(217) },
          { UINT8_C(107), UINT8_C(120), UINT8_C(182), UINT8_C( 17), UINT8_C( 73), UINT8_C(119), UINT8_C(133), UINT8_C(213),
            UINT8_C( 26), UINT8_C( 55), UINT8_C(107), UINT8_C(132), UINT8_C(139), UINT8_C(120), UINT8_C(165), UINT8_C(147) },
          { UINT8_C(203), UINT8_C(107), UINT8_C(186), UINT8_C(159), UINT8_C(161), UINT8_C( 98), UINT8_C(169), UINT8_C( 72),
            UINT8_C(189), UINT8_C(245), UINT8_C(219), UINT8_C(239), UINT8_C( 28), UINT8_C( 37), UINT8_C(200), UINT8_C(136) },
          { UINT8_C(157), UINT8_C(127), UINT8_C(153), UINT8_C(230), UINT8_C(246), UINT8_C( 31), UINT8_C(188), UINT8_C( 17),
            UINT8_C( 86), UINT8_C( 39), UINT8_C(149), UINT8_C(225), UINT8_C(159), UINT8_C( 59), UINT8_C(117), UINT8_C(106) } },
      { UINT8_C(  8), UINT8_C( 83), UINT8_C(198), UINT8_C( 38), UINT8_C(212), UINT8_C( 53), UINT8_C(168), UINT8_C(  9),
        UINT8_C(167), UINT8_C( 91), UINT8_C( 76), UINT8_C(147), UINT8_C( 50), UINT8_C( 39), UINT8_C( 74), UINT8_C(217),
        UINT8_C(107), UINT8_C(120), UINT8_C(182), UINT8_C( 17), UINT8_C( 73), UINT8_C(119), UINT8_C(133), UINT8_C(213),
        UINT8_C( 26), UINT8_C( 55), UINT8_C(107), UINT8_C(132), UINT8_C(139), UINT8_C(120), UINT8_C(165), UINT8_C(147),
        UINT8_C(203), UINT8_C(107), UINT8_C(186), UINT8_C(159), UINT8_C(161), UINT8_C( 98), UINT8_C(169), UINT8_C( 72),
        UINT8_C(189), UINT8_C(245), UINT8_C(219), UINT8_C(239), UINT8_C( 28), UINT8_C( 37), UINT8_C(200), UINT8_C(136),
        UINT8_C(157), UINT8_C(127), UINT8_C(153), UINT8_C(230), UINT8_C(246), UINT8_C( 31), UINT8_C(188), UINT8_C( 17),
        UINT8_C( 86), UINT8_C( 39), UINT8_C(149), UINT8_C(225), UINT8_C(159), UINT8_C( 59), UINT8_C(117), UINT8_C(106) } },
    {
        { { UINT8_C(166), UINT8_C( 47), UINT8_C(  9), UINT8_C( 71), UINT8_C(145), UINT8_C(178), UINT8_C(144), UINT8_C( 78),
            UINT8_C(168), UINT8_C(107), UINT8_C( 61), UINT8_C(196), UINT8_C(145), UINT8_C(  5), UINT8_C( 76), UINT8_C( 46) },
          { UINT8_C(132), UINT8_C(230), UINT8_C( 21), UINT8_C(123), UINT8_C(  5), UINT8_C(209), UINT8_C(140), UINT8_C( 91),
            UINT8_C(248), UINT8_C( 33), UINT8_C( 60), UINT8_C(151), UINT8_C( 92), UINT8_C(177), UINT8_C(  1), UINT8_C(  3) },
          { UINT8_C(224), UINT8_C( 10), UINT8_C( 74), UINT8_C(113), UINT8_C(189), UINT8_C(218), UINT8_C(191), UINT8_C(101),
            UINT8_C( 70), UINT8_C(252), UINT8_C( 41), UINT8_C(215), UINT8_C(  2), UINT8_C(118), UINT8_C(  5), UINT8_C(134) },
          { UINT8_C( 92), UINT8_C( 26), UINT8_C(  1), UINT8_C( 97), UINT8_C(235), UINT8_C(141), UINT8_C(188), UINT8_C(227),
            UINT8_C(175), UINT8_C(248), UINT8_C(122), UINT8_C( 11), UINT8_C(170), UINT8_C(123), UINT8_C( 14), UINT8_C(138) } },
      { UINT8_C(166), UINT8_C( 47), UINT8_C(  9), UINT8_C( 71), UINT8_C(145), UINT8_C(178), UINT8_C(144), UINT8_C( 78),
        UINT8_C(168), UINT8_C(107), UINT8_C( 61), UINT8_C(196), UINT8_C(145), UINT8_C(  5), UINT8_C( 76), UINT8_C( 46),
        UINT8_C(132), UINT8_C(230), UINT8_C( 21), UINT8_C(123), UINT8_C(  5), UINT8_C(209), UINT8_C(140), UINT8_C( 91),
        UINT8_C(248), UINT8_C( 33), UINT8_C( 60), UINT8_C(151), UINT8_C( 92), UINT8_C(177), UINT8_C(  1), UINT8_C(  3),
        UINT8_C(224), UINT8_C( 10), UINT8_C( 74), UINT8_C(113), UINT8_C(189), UINT8_C(218), UINT8_C(191), UINT8_C(101),
        UINT8_C( 70), UINT8_C(252), UINT8_C( 41), UINT8_C(215), UINT8_C(  2), UINT8_C(118), UINT8_C(  5), UINT8_C(134),
        UINT8_C( 92), UINT8_C( 26), UINT8_C(  1), UINT8_C( 97), UINT8_C(235), UINT8_C(141), UINT8_C(188), UINT8_C(227),
        UINT8_C(175), UINT8_C(248), UINT8_C(122), UINT8_C( 11), UINT8_C(170), UINT8_C(123), UINT8_C( 14), UINT8_C(138) } },
    {
        { { UINT8_C(134), UINT8_C( 89), UINT8_C(252), UINT8_C( 67), UINT8_C( 51), UINT8_C(187), UINT8_C(168), UINT8_C(121),
            UINT8_C(184), UINT8_C(209), UINT8_C( 80), UINT8_C(186), UINT8_C( 71), UINT8_C( 86), UINT8_C( 64), UINT8_C(163) },
          { UINT8_C(112), UINT8_C( 66), UINT8_C(  4), UINT8_C( 92), UINT8_C(207), UINT8_C(192), UINT8_C( 63), UINT8_C(126),
            UINT8_C(185), UINT8_C(186), UINT8_C(138), UINT8_C( 99), UINT8_C( 53), UINT8_C(152), UINT8_C(237), UINT8_C(187) },
          { UINT8_C(241), UINT8_C(233), UINT8_C(254), UINT8_C( 37), UINT8_C(165), UINT8_C(166), UINT8_C(158), UINT8_C( 93),
            UINT8_C(120), UINT8_C(239), UINT8_C( 23), UINT8_C(191), UINT8_C( 69), UINT8_C( 87), UINT8_C( 99), UINT8_C(181) },
          { UINT8_C(153), UINT8_C(103), UINT8_C( 17), UINT8_C(105), UINT8_C( 40), UINT8_C( 81), UINT8_C(231), UINT8_C(225),
            UINT8_C( 11), UINT8_C(113), UINT8_C( 68), UINT8_C( 64), UINT8_C( 10), UINT8_C( 49), UINT8_C(252), UINT8_C(251) } },
      { UINT8_C(134), UINT8_C( 89), UINT8_C(252), UINT8_C( 67), UINT8_C( 51), UINT8_C(187), UINT8_C(168), UINT8_C(121),
        UINT8_C(184), UINT8_C(209), UINT8_C( 80), UINT8_C(186), UINT8_C( 71), UINT8_C( 86), UINT8_C( 64), UINT8_C(163),
        UINT8_C(112), UINT8_C( 66), UINT8_C(  4), UINT8_C( 92), UINT8_C(207), UINT8_C(192), UINT8_C( 63), UINT8_C(126),
        UINT8_C(185), UINT8_C(186), UINT8_C(138), UINT8_C( 99), UINT8_C( 53), UINT8_C(152), UINT8_C(237), UINT8_C(187),
        UINT8_C(241), UINT8_C(233), UINT8_C(254), UINT8_C( 37), UINT8_C(165), UINT8_C(166), UINT8_C(158), UINT8_C( 93),
        UINT8_C(120), UINT8_C(239), UINT8_C( 23), UINT8_C(191), UINT8_C( 69), UINT8_C( 87), UINT8_C( 99), UINT8_C(181),
        UINT8_C(153), UINT8_C(103), UINT8_C( 17), UINT8_C(105), UINT8_C( 40), UINT8_C( 81), UINT8_C(231), UINT8_C(225),
        UINT8_C( 11), UINT8_C(113), UINT8_C( 68), UINT8_C( 64), UINT8_C( 10), UINT8_C( 49), UINT8_C(252), UINT8_C(251) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x16x4_t r_ = { { simde_vld1q_u8(test_vec[i].r[0]),
                                simde_vld1q_u8(test_vec[i].r[1]),
                                simde_vld1q_u8(test_vec[i].r[2]),
                                simde_vld1q_u8(test_vec[i].r[3]) } };

    uint8_t a_[64];
    simde_vst1q_u8_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x16_t a = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t b = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t c = simde_test_arm_neon_random_u8x16();
    simde_uint8x16_t d = simde_test_arm_neon_random_u8x16();
    simde_uint8x16x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_u8x16x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    uint8_t buf[64];
    simde_vst1q_u8_x4(buf, e);

    simde_test_codegen_write_vu8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u16_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[4][8];
    uint16_t a[32];
  } test_vec[] = {
    {
        { { UINT16_C(64027), UINT16_C(49184), UINT16_C(49057), UINT16_C( 6429), UINT16_C(13486), UINT16_C(62424), UINT16_C(15243), UINT16_C( 9640) },
          { UINT16_C(47779), UINT16_C(52110), UINT16_C(29963), UINT16_C( 5804), UINT16_C(61671), UINT16_C(61782), UINT16_C(21025), UINT16_C(15596) },
          { UINT16_C( 3405), UINT16_C(61180), UINT16_C( 6604), UINT16_C(31239), UINT16_C(57165), UINT16_C(55661), UINT16_C( 5403), UINT16_C(48894) },
          { UINT16_C(36047), UINT16_C(55945), UINT16_C(13569), UINT16_C(59632), UINT16_C(18213), UINT16_C(18137), UINT16_C(50841), UINT16_C(59011) } },
      { UINT16_C(64027), UINT16_C(49184), UINT16_C(49057), UINT16_C( 6429), UINT16_C(13486), UINT16_C(62424), UINT16_C(15243), UINT16_C( 9640),
        UINT16_C(47779), UINT16_C(52110), UINT16_C(29963), UINT16_C( 5804), UINT16_C(61671), UINT16_C(61782), UINT16_C(21025), UINT16_C(15596),
        UINT16_C( 3405), UINT16_C(61180), UINT16_C( 6604), UINT16_C(31239), UINT16_C(57165), UINT16_C(55661), UINT16_C( 5403), UINT16_C(48894),
        UINT16_C(36047), UINT16_C(55945), UINT16_C(13569), UINT16_C(59632), UINT16_C(18213), UINT16_C(18137), UINT16_C(50841), UINT16_C(59011) } },
    {
        { { UINT16_C(32723), UINT16_C(40916), UINT16_C(56217), UINT16_C(58905), UINT16_C(34491), UINT16_C(54975), UINT16_C(48539), UINT16_C(27540) },
          { UINT16_C( 7497), UINT16_C(19269), UINT16_C(13906), UINT16_C(30515), UINT16_C( 3453), UINT16_C( 5821), UINT16_C(16595), UINT16_C(42749) },
          { UINT16_C(53696), UINT16_C(22853), UINT16_C(24237), UINT16_C(26687), UINT16_C(65508), UINT16_C(32574), UINT16_C(53948), UINT16_C( 1770) },
          { UINT16_C(12527), UINT16_C(16721), UINT16_C(33894), UINT16_C(58296), UINT16_C(30097), UINT16_C(25849), UINT16_C(63158), UINT16_C(30218) } },
      { UINT16_C(32723), UINT16_C(40916), UINT16_C(56217), UINT16_C(58905), UINT16_C(34491), UINT16_C(54975), UINT16_C(48539), UINT16_C(27540),
        UINT16_C( 7497), UINT16_C(19269), UINT16_C(13906), UINT16_C(30515), UINT16_C( 3453), UINT16_C( 5821), UINT16_C(16595), UINT16_C(42749),
        UINT16_C(53696), UINT16_C(22853), UINT16_C(24237), UINT16_C(26687), UINT16_C(65508), UINT16_C(32574), UINT16_C(53948), UINT16_C( 1770),
        UINT16_C(12527), UINT16_C(16721), UINT16_C(33894), UINT16_C(58296), UINT16_C(30097), UINT16_C(25849), UINT16_C(63158), UINT16_C(30218) } },
    {
        { { UINT16_C(20424), UINT16_C(30159), UINT16_C( 3757), UINT16_C(37341), UINT16_C( 6925), UINT16_C(51729), UINT16_C(64493), UINT16_C(56528) },
          { UINT16_C( 8491), UINT16_C(37149), UINT16_C(54693), UINT16_C(14196), UINT16_C(28234), UINT16_C(  155), UINT16_C(42596), UINT16_C(11382) },
          { UINT16_C(17909), UINT16_C(41889), UINT16_C(32340), UINT16_C(24884), UINT16_C(17817), UINT16_C(34347), UINT16_C(64321), UINT16_C(27746) },
          { UINT16_C(32540), UINT16_C(49918), UINT16_C(29268), UINT16_C(40953), UINT16_C(38112), UINT16_C(17823), UINT16_C( 5690), UINT16_C(12401) } },
      { UINT16_C(20424), UINT16_C(30159), UINT16_C( 3757), UINT16_C(37341), UINT16_C( 6925), UINT16_C(51729), UINT16_C(64493), UINT16_C(56528),
        UINT16_C( 8491), UINT16_C(37149), UINT16_C(54693), UINT16_C(14196), UINT16_C(28234), UINT16_C(  155), UINT16_C(42596), UINT16_C(11382),
        UINT16_C(17909), UINT16_C(41889), UINT16_C(32340), UINT16_C(24884), UINT16_C(17817), UINT16_C(34347), UINT16_C(64321), UINT16_C(27746),
        UINT16_C(32540), UINT16_C(49918), UINT16_C(29268), UINT16_C(40953), UINT16_C(38112), UINT16_C(17823), UINT16_C( 5690), UINT16_C(12401) } },
    {
        { { UINT16_C( 4955), UINT16_C(45011), UINT16_C( 1937), UINT16_C(11025), UINT16_C(15437), UINT16_C(36529), UINT16_C( 5176), UINT16_C(21754) },
          { UINT16_C(63635), UINT16_C(59414), UINT16_C( 3947), UINT16_C(19335), UINT16_C( 9892), UINT16_C(56976), UINT16_C(  572), UINT16_C(38926) },
          { UINT16_C(57621), UINT16_C(42567), UINT16_C(22761), UINT16_C(14033), UINT16_C(33685), UINT16_C(52676), UINT16_C(48791), UINT16_C(10785) },
          { UINT16_C(14519), UINT16_C( 8722), UINT16_C(39239), UINT16_C(60269), UINT16_C(65216), UINT16_C(64714), UINT16_C(55296), UINT16_C( 5524) } },
      { UINT16_C( 4955), UINT16_C(45011), UINT16_C( 1937), UINT16_C(11025), UINT16_C(15437), UINT16_C(36529), UINT16_C( 5176), UINT16_C(21754),
        UINT16_C(63635), UINT16_C(59414), UINT16_C( 3947), UINT16_C(19335), UINT16_C( 9892), UINT16_C(56976), UINT16_C(  572), UINT16_C(38926),
        UINT16_C(57621), UINT16_C(42567), UINT16_C(22761), UINT16_C(14033), UINT16_C(33685), UINT16_C(52676), UINT16_C(48791), UINT16_C(10785),
        UINT16_C(14519), UINT16_C( 8722), UINT16_C(39239), UINT16_C(60269), UINT16_C(65216), UINT16_C(64714), UINT16_C(55296), UINT16_C( 5524) } },
    {
        { { UINT16_C(56506), UINT16_C(41915), UINT16_C(36148), UINT16_C(51673), UINT16_C(40208), UINT16_C(42902), UINT16_C(47195), UINT16_C( 4817) },
          { UINT16_C(58608), UINT16_C(14132), UINT16_C(41597), UINT16_C(15651), UINT16_C(60832), UINT16_C(41018), UINT16_C(52933), UINT16_C(32693) },
          { UINT16_C(28842), UINT16_C(57122), UINT16_C(64509), UINT16_C( 3496), UINT16_C(16280), UINT16_C(62644), UINT16_C(34551), UINT16_C(59142) },
          { UINT16_C(15210), UINT16_C(59166), UINT16_C(16861), UINT16_C(32037), UINT16_C(24366), UINT16_C(62493), UINT16_C(53805), UINT16_C(55411) } },
      { UINT16_C(56506), UINT16_C(41915), UINT16_C(36148), UINT16_C(51673), UINT16_C(40208), UINT16_C(42902), UINT16_C(47195), UINT16_C( 4817),
        UINT16_C(58608), UINT16_C(14132), UINT16_C(41597), UINT16_C(15651), UINT16_C(60832), UINT16_C(41018), UINT16_C(52933), UINT16_C(32693),
        UINT16_C(28842), UINT16_C(57122), UINT16_C(64509), UINT16_C( 3496), UINT16_C(16280), UINT16_C(62644), UINT16_C(34551), UINT16_C(59142),
        UINT16_C(15210), UINT16_C(59166), UINT16_C(16861), UINT16_C(32037), UINT16_C(24366), UINT16_C(62493), UINT16_C(53805), UINT16_C(55411) } },
    {
        { { UINT16_C(38466), UINT16_C(16567), UINT16_C(24465), UINT16_C(10829), UINT16_C(  670), UINT16_C(38174), UINT16_C( 9352), UINT16_C(62076) },
          { UINT16_C(39775), UINT16_C(15577), UINT16_C(65244), UINT16_C( 3001), UINT16_C(54877), UINT16_C(35839), UINT16_C(29352), UINT16_C(60259) },
          { UINT16_C( 6664), UINT16_C(39467), UINT16_C(30841), UINT16_C( 6340), UINT16_C(57978), UINT16_C(  685), UINT16_C(10758), UINT16_C(26356) },
          { UINT16_C(52933), UINT16_C(41378), UINT16_C(23756), UINT16_C(10924), UINT16_C(43826), UINT16_C(56245), UINT16_C( 6174), UINT16_C( 9926) } },
      { UINT16_C(38466), UINT16_C(16567), UINT16_C(24465), UINT16_C(10829), UINT16_C(  670), UINT16_C(38174), UINT16_C( 9352), UINT16_C(62076),
        UINT16_C(39775), UINT16_C(15577), UINT16_C(65244), UINT16_C( 3001), UINT16_C(54877), UINT16_C(35839), UINT16_C(29352), UINT16_C(60259),
        UINT16_C( 6664), UINT16_C(39467), UINT16_C(30841), UINT16_C( 6340), UINT16_C(57978), UINT16_C(  685), UINT16_C(10758), UINT16_C(26356),
        UINT16_C(52933), UINT16_C(41378), UINT16_C(23756), UINT16_C(10924), UINT16_C(43826), UINT16_C(56245), UINT16_C( 6174), UINT16_C( 9926) } },
    {
        { { UINT16_C(61746), UINT16_C(43968), UINT16_C(33897), UINT16_C(58563), UINT16_C(29030), UINT16_C(28134), UINT16_C(56219), UINT16_C(24787) },
          { UINT16_C(30121), UINT16_C(29953), UINT16_C(44753), UINT16_C( 1183), UINT16_C(21593), UINT16_C(30687), UINT16_C(42348), UINT16_C(40606) },
          { UINT16_C(24214), UINT16_C(65354), UINT16_C( 3555), UINT16_C(18915), UINT16_C(51838), UINT16_C( 6582), UINT16_C(35237), UINT16_C(20089) },
          { UINT16_C(31743), UINT16_C(53443), UINT16_C(25385), UINT16_C(33492), UINT16_C(46007), UINT16_C( 9466), UINT16_C(39000), UINT16_C(61122) } },
      { UINT16_C(61746), UINT16_C(43968), UINT16_C(33897), UINT16_C(58563), UINT16_C(29030), UINT16_C(28134), UINT16_C(56219), UINT16_C(24787),
        UINT16_C(30121), UINT16_C(29953), UINT16_C(44753), UINT16_C( 1183), UINT16_C(21593), UINT16_C(30687), UINT16_C(42348), UINT16_C(40606),
        UINT16_C(24214), UINT16_C(65354), UINT16_C( 3555), UINT16_C(18915), UINT16_C(51838), UINT16_C( 6582), UINT16_C(35237), UINT16_C(20089),
        UINT16_C(31743), UINT16_C(53443), UINT16_C(25385), UINT16_C(33492), UINT16_C(46007), UINT16_C( 9466), UINT16_C(39000), UINT16_C(61122) } },
    {
        { { UINT16_C( 3318), UINT16_C(55790), UINT16_C(53530), UINT16_C(38947), UINT16_C(55707), UINT16_C(16562), UINT16_C(11107), UINT16_C(25230) },
          { UINT16_C(21158), UINT16_C(53042), UINT16_C( 1973), UINT16_C(27730), UINT16_C(19642), UINT16_C( 5008), UINT16_C(21476), UINT16_C(55809) },
          { UINT16_C(61279), UINT16_C(31156), UINT16_C(55233), UINT16_C(23570), UINT16_C(50352), UINT16_C( 5021), UINT16_C(11247), UINT16_C(38517) },
          { UINT16_C(43133), UINT16_C(12901), UINT16_C(47023), UINT16_C(27039), UINT16_C(12035), UINT16_C(59260), UINT16_C(32386), UINT16_C(58050) } },
      { UINT16_C( 3318), UINT16_C(55790), UINT16_C(53530), UINT16_C(38947), UINT16_C(55707), UINT16_C(16562), UINT16_C(11107), UINT16_C(25230),
        UINT16_C(21158), UINT16_C(53042), UINT16_C( 1973), UINT16_C(27730), UINT16_C(19642), UINT16_C( 5008), UINT16_C(21476), UINT16_C(55809),
        UINT16_C(61279), UINT16_C(31156), UINT16_C(55233), UINT16_C(23570), UINT16_C(50352), UINT16_C( 5021), UINT16_C(11247), UINT16_C(38517),
        UINT16_C(43133), UINT16_C(12901), UINT16_C(47023), UINT16_C(27039), UINT16_C(12035), UINT16_C(59260), UINT16_C(32386), UINT16_C(58050) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x8x4_t r_ = { { simde_vld1q_u16(test_vec[i].r[0]),
                                simde_vld1q_u16(test_vec[i].r[1]),
                                simde_vld1q_u16(test_vec[i].r[2]),
                                simde_vld1q_u16(test_vec[i].r[3]) } };

    uint16_t a_[32];
    simde_vst1q_u16_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x8_t a = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t b = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t c = simde_test_arm_neon_random_u16x8();
    simde_uint16x8_t d = simde_test_arm_neon_random_u16x8();
    simde_uint16x8x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_u16x8x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    uint16_t buf[32];
    simde_vst1q_u16_x4(buf, e);

    simde_test_codegen_write_vu16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u32_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[4][4];
    uint32_t a[16];
  } test_vec[] = {
    {
        { { UINT32_C( 777746029), UINT32_C(4253773133), UINT32_C( 554772529), UINT32_C(3518465619) },
          { UINT32_C(3707968558), UINT32_C(3611796180), UINT32_C(1421853650), UINT32_C(2939584833) },
          { UINT32_C(1155371767), UINT32_C( 826370303), UINT32_C(3830600336), UINT32_C( 129305049) },
          { UINT32_C(4192581669), UINT32_C( 768683099), UINT32_C( 830574831), UINT32_C( 148944913) } },
      { UINT32_C( 777746029), UINT32_C(4253773133), UINT32_C( 554772529), UINT32_C(3518465619), UINT32_C(3707968558), UINT32_C(3611796180), UINT32_C(1421853650), UINT32_C(2939584833),
        UINT32_C(1155371767), UINT32_C( 826370303), UINT32_C(3830600336), UINT32_C( 129305049), UINT32_C(4192581669), UINT32_C( 768683099), UINT32_C( 830574831), UINT32_C( 148944913) } },
    {
        { { UINT32_C(1229765962), UINT32_C(3061484838), UINT32_C(3113929952), UINT32_C(4223684565) },
          { UINT32_C(1676977416), UINT32_C(3247490513), UINT32_C(1727140181), UINT32_C( 326030025) },
          { UINT32_C(3042818703), UINT32_C( 678221640), UINT32_C(2044790436), UINT32_C(1584701782) },
          { UINT32_C( 415328583), UINT32_C(2228834606), UINT32_C( 753584994), UINT32_C( 759126429) } },
      { UINT32_C(1229765962), UINT32_C(3061484838), UINT32_C(3113929952), UINT32_C(4223684565), UINT32_C(1676977416), UINT32_C(3247490513), UINT32_C(1727140181), UINT32_C( 326030025),
        UINT32_C(3042818703), UINT32_C( 678221640), UINT32_C(2044790436), UINT32_C(1584701782), UINT32_C( 415328583), UINT32_C(2228834606), UINT32_C( 753584994), UINT32_C( 759126429) } },
    {
        { { UINT32_C(1541577747), UINT32_C( 411258484), UINT32_C(2878432341), UINT32_C(1292436998) },
          { UINT32_C(2640693871), UINT32_C(2099330843), UINT32_C(2829650954), UINT32_C(2027284837) },
          { UINT32_C(4191467397), UINT32_C(1527863046), UINT32_C(3255215036), UINT32_C( 403640233) },
          { UINT32_C(4105532633), UINT32_C(3195131827), UINT32_C(1214651363), UINT32_C(2311076612) } },
      { UINT32_C(1541577747), UINT32_C( 411258484), UINT32_C(2878432341), UINT32_C(1292436998), UINT32_C(2640693871), UINT32_C(2099330843), UINT32_C(2829650954), UINT32_C(2027284837),
        UINT32_C(4191467397), UINT32_C(1527863046), UINT32_C(3255215036), UINT32_C( 403640233), UINT32_C(4105532633), UINT32_C(3195131827), UINT32_C(1214651363), UINT32_C(2311076612) } },
    {
        { { UINT32_C(4169372914), UINT32_C(2824049900), UINT32_C(3765066039), UINT32_C(1106803048) },
          { UINT32_C(2704649965), UINT32_C(1751099269), UINT32_C(3333473730), UINT32_C(4065292288) },
          { UINT32_C(4058763781), UINT32_C(2660843111), UINT32_C(   8323992), UINT32_C(1765963644) },
          { UINT32_C(2852812581), UINT32_C(3759302942), UINT32_C( 782680622), UINT32_C( 941749811) } },
      { UINT32_C(4169372914), UINT32_C(2824049900), UINT32_C(3765066039), UINT32_C(1106803048), UINT32_C(2704649965), UINT32_C(1751099269), UINT32_C(3333473730), UINT32_C(4065292288),
        UINT32_C(4058763781), UINT32_C(2660843111), UINT32_C(   8323992), UINT32_C(1765963644), UINT32_C(2852812581), UINT32_C(3759302942), UINT32_C( 782680622), UINT32_C( 941749811) } },
    {
        { { UINT32_C( 791219400), UINT32_C(3805200970), UINT32_C(1105415621), UINT32_C(3937019332) },
          { UINT32_C(3147085212), UINT32_C(1302046494), UINT32_C(2625323625), UINT32_C(  13933624) },
          { UINT32_C(4080074152), UINT32_C(2228616895), UINT32_C( 264616011), UINT32_C(2063167709) },
          { UINT32_C(1127583269), UINT32_C(2660290613), UINT32_C(1245383698), UINT32_C(1363873704) } },
      { UINT32_C( 791219400), UINT32_C(3805200970), UINT32_C(1105415621), UINT32_C(3937019332), UINT32_C(3147085212), UINT32_C(1302046494), UINT32_C(2625323625), UINT32_C(  13933624),
        UINT32_C(4080074152), UINT32_C(2228616895), UINT32_C( 264616011), UINT32_C(2063167709), UINT32_C(1127583269), UINT32_C(2660290613), UINT32_C(1245383698), UINT32_C(1363873704) } },
    {
        { { UINT32_C(3427040013), UINT32_C(3293649273), UINT32_C(2949846738), UINT32_C(2871643526) },
          { UINT32_C(2431606363), UINT32_C(1093566255), UINT32_C( 881617291), UINT32_C(2256918393) },
          { UINT32_C(3411200338), UINT32_C(3029312482), UINT32_C(1080320698), UINT32_C(2330758447) },
          { UINT32_C( 454745068), UINT32_C(3864807770), UINT32_C( 723183794), UINT32_C( 296853439) } },
      { UINT32_C(3427040013), UINT32_C(3293649273), UINT32_C(2949846738), UINT32_C(2871643526), UINT32_C(2431606363), UINT32_C(1093566255), UINT32_C( 881617291), UINT32_C(2256918393),
        UINT32_C(3411200338), UINT32_C(3029312482), UINT32_C(1080320698), UINT32_C(2330758447), UINT32_C( 454745068), UINT32_C(3864807770), UINT32_C( 723183794), UINT32_C( 296853439) } },
    {
        { { UINT32_C(1255933032), UINT32_C(1644129191), UINT32_C(4255278030), UINT32_C(3699937008) },
          { UINT32_C(3287786089), UINT32_C(2661897451), UINT32_C(4241081148), UINT32_C(3389881186) },
          { UINT32_C( 638970495), UINT32_C( 596120661), UINT32_C(1730226807), UINT32_C( 558148024) },
          { UINT32_C( 937704267), UINT32_C(3436547727), UINT32_C(3033046609), UINT32_C(2558448921) } },
      { UINT32_C(1255933032), UINT32_C(1644129191), UINT32_C(4255278030), UINT32_C(3699937008), UINT32_C(3287786089), UINT32_C(2661897451), UINT32_C(4241081148), UINT32_C(3389881186),
        UINT32_C( 638970495), UINT32_C( 596120661), UINT32_C(1730226807), UINT32_C( 558148024), UINT32_C( 937704267), UINT32_C(3436547727), UINT32_C(3033046609), UINT32_C(2558448921) } },
    {
        { { UINT32_C( 364876735), UINT32_C( 507004839), UINT32_C( 696670577), UINT32_C(1313524226) },
          { UINT32_C(2508533253), UINT32_C( 241261244), UINT32_C( 314714616), UINT32_C(3198828798) },
          { UINT32_C(2077452756), UINT32_C( 563743664), UINT32_C(1732911205), UINT32_C(4021654762) },
          { UINT32_C(2139372227), UINT32_C(2374886804), UINT32_C( 228544270), UINT32_C(1691044240) } },
      { UINT32_C( 364876735), UINT32_C( 507004839), UINT32_C( 696670577), UINT32_C(1313524226), UINT32_C(2508533253), UINT32_C( 241261244), UINT32_C( 314714616), UINT32_C(3198828798),
        UINT32_C(2077452756), UINT32_C( 563743664), UINT32_C(1732911205), UINT32_C(4021654762), UINT32_C(2139372227), UINT32_C(2374886804), UINT32_C( 228544270), UINT32_C(1691044240) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x4x4_t r_ = { { simde_vld1q_u32(test_vec[i].r[0]),
                                simde_vld1q_u32(test_vec[i].r[1]),
                                simde_vld1q_u32(test_vec[i].r[2]),
                                simde_vld1q_u32(test_vec[i].r[3]) } };

    uint32_t a_[16];
    simde_vst1q_u32_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x4_t a = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t b = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t c = simde_test_arm_neon_random_u32x4();
    simde_uint32x4_t d = simde_test_arm_neon_random_u32x4();
    simde_uint32x4x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_u32x4x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    uint32_t buf[16];
    simde_vst1q_u32_x4(buf, e);

    simde_test_codegen_write_vu32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1q_u64_x4 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r[4][2];
    uint64_t a[8];
  } test_vec[] = {
    {
        { { UINT64_C( 1046376256865541811), UINT64_C( 2842663500503240601) },
          { UINT64_C(16971591848766666598), UINT64_C( 2555726199694829187) },
          { UINT64_C( 7645154830612584289), UINT64_C( 2406717408223793115) },
          { UINT64_C(14132475126852815960), UINT64_C( 4493554335490709961) } },
      { UINT64_C( 1046376256865541811), UINT64_C( 2842663500503240601), UINT64_C(16971591848766666598), UINT64_C( 2555726199694829187),
        UINT64_C( 7645154830612584289), UINT64_C( 2406717408223793115), UINT64_C(14132475126852815960), UINT64_C( 4493554335490709961) } },
    {
        { { UINT64_C(14546735572732994470), UINT64_C( 9713822593035325170) },
          { UINT64_C( 6232942906307242363), UINT64_C( 5480859472757741557) },
          { UINT64_C(12504142917155313871), UINT64_C( 8729710001764601713) },
          { UINT64_C(12895130359564656913), UINT64_C( 4538946107388232459) } },
      { UINT64_C(14546735572732994470), UINT64_C( 9713822593035325170), UINT64_C( 6232942906307242363), UINT64_C( 5480859472757741557),
        UINT64_C(12504142917155313871), UINT64_C( 8729710001764601713), UINT64_C(12895130359564656913), UINT64_C( 4538946107388232459) } },
    {
        { { UINT64_C(15227940699794882540), UINT64_C(16684035439248780818) },
          { UINT64_C( 9073197930772807290), UINT64_C(17197886891449282301) },
          { UINT64_C( 4332719209429968874), UINT64_C(12057497588678366103) },
          { UINT64_C( 5801702103418133140), UINT64_C(14350835507703689528) } },
      { UINT64_C(15227940699794882540), UINT64_C(16684035439248780818), UINT64_C( 9073197930772807290), UINT64_C(17197886891449282301),
        UINT64_C( 4332719209429968874), UINT64_C(12057497588678366103), UINT64_C( 5801702103418133140), UINT64_C(14350835507703689528) } },
    {
        { { UINT64_C( 4428503697115626767), UINT64_C( 3286500290285191880) },
          { UINT64_C( 8970246061242481368), UINT64_C(12685759034636515689) },
          { UINT64_C( 2125240893948108955), UINT64_C(18440179056110544929) },
          { UINT64_C( 4388660888373763111), UINT64_C( 1599778953768377825) } },
      { UINT64_C( 4428503697115626767), UINT64_C( 3286500290285191880), UINT64_C( 8970246061242481368), UINT64_C(12685759034636515689),
        UINT64_C( 2125240893948108955), UINT64_C(18440179056110544929), UINT64_C( 4388660888373763111), UINT64_C( 1599778953768377825) } },
    {
        { { UINT64_C(11322565662516649135), UINT64_C(  514325010070319869) },
          { UINT64_C(15450542955734126171), UINT64_C( 3137193081579367927) },
          { UINT64_C(13024780340553572776), UINT64_C(12928140562377742466) },
          { UINT64_C( 3248588696812968777), UINT64_C(11736989735680241211) } },
      { UINT64_C(11322565662516649135), UINT64_C(  514325010070319869), UINT64_C(15450542955734126171), UINT64_C( 3137193081579367927),
        UINT64_C(13024780340553572776), UINT64_C(12928140562377742466), UINT64_C( 3248588696812968777), UINT64_C(11736989735680241211) } },
    {
        { { UINT64_C(16462212866855276810), UINT64_C(10496676084454935968) },
          { UINT64_C( 1724285869131533962), UINT64_C(13974583565284773202) },
          { UINT64_C(15927251924173370819), UINT64_C( 9808137389960678980) },
          { UINT64_C( 2522637916975983630), UINT64_C( 4988123076260581826) } },
      { UINT64_C(16462212866855276810), UINT64_C(10496676084454935968), UINT64_C( 1724285869131533962), UINT64_C(13974583565284773202),
        UINT64_C(15927251924173370819), UINT64_C( 9808137389960678980), UINT64_C( 2522637916975983630), UINT64_C( 4988123076260581826) } },
    {
        { { UINT64_C(17739242092454656788), UINT64_C(10540287370387915713) },
          { UINT64_C( 9619829281127239308), UINT64_C( 7212575619215716432) },
          { UINT64_C(13086586356635108083), UINT64_C( 5403961929900498663) },
          { UINT64_C( 5373401260314032969), UINT64_C(13459909942359920664) } },
      { UINT64_C(17739242092454656788), UINT64_C(10540287370387915713), UINT64_C( 9619829281127239308), UINT64_C( 7212575619215716432),
        UINT64_C(13086586356635108083), UINT64_C( 5403961929900498663), UINT64_C( 5373401260314032969), UINT64_C(13459909942359920664) } },
    {
        { { UINT64_C( 5503676258243871158), UINT64_C(15574211190333166618) },
          { UINT64_C(  681581696812108081), UINT64_C( 8973489082100388102) },
          { UINT64_C(18405799240516757693), UINT64_C(  991912169708136028) },
          { UINT64_C( 2719520097385883843), UINT64_C( 2846692134771437119) } },
      { UINT64_C( 5503676258243871158), UINT64_C(15574211190333166618), UINT64_C(  681581696812108081), UINT64_C( 8973489082100388102),
        UINT64_C(18405799240516757693), UINT64_C(  991912169708136028), UINT64_C( 2719520097385883843), UINT64_C( 2846692134771437119) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x2x4_t r_ = { { simde_vld1q_u64(test_vec[i].r[0]),
                                simde_vld1q_u64(test_vec[i].r[1]),
                                simde_vld1q_u64(test_vec[i].r[2]),
                                simde_vld1q_u64(test_vec[i].r[3]) } };

    uint64_t a_[8];
    simde_vst1q_u64_x4(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x2_t a = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t b = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t c = simde_test_arm_neon_random_u64x2();
    simde_uint64x2_t d = simde_test_arm_neon_random_u64x2();
    simde_uint64x2x4_t e = {{a, b, c, d}};

    simde_test_arm_neon_write_u64x2x4(2, e, SIMDE_TEST_VEC_POS_FIRST);

    uint64_t buf[8];
    simde_vst1q_u64_x4(buf, e);

    simde_test_codegen_write_vu64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_f32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_f64_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s8_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s16_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_s64_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u8_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u16_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u32_x4)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1q_u64_x4)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
