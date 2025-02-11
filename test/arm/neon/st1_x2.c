
#include "test/test.h"
#define SIMDE_TEST_ARM_NEON_INSN st1_x2
#include "test-neon.h"
#include "../../../simde/arm/neon/st1_x2.h"

#if !defined(SIMDE_BUG_INTEL_857088)

static int
test_simde_vst1_f32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float32 r[2][2];
    simde_float32 a[4];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT32_C(   768.40), SIMDE_FLOAT32_C(   597.15) },
          { SIMDE_FLOAT32_C(   753.33), SIMDE_FLOAT32_C(  -342.42) } },
      { SIMDE_FLOAT32_C(   768.40), SIMDE_FLOAT32_C(   597.15), SIMDE_FLOAT32_C(   753.33), SIMDE_FLOAT32_C(  -342.42) } },
    {
        { { SIMDE_FLOAT32_C(    56.78), SIMDE_FLOAT32_C(   403.46) },
          { SIMDE_FLOAT32_C(   878.90), SIMDE_FLOAT32_C(  -758.81) } },
      { SIMDE_FLOAT32_C(    56.78), SIMDE_FLOAT32_C(   403.46), SIMDE_FLOAT32_C(   878.90), SIMDE_FLOAT32_C(  -758.81) } },
    {
        { { SIMDE_FLOAT32_C(   936.16), SIMDE_FLOAT32_C(   350.75) },
          { SIMDE_FLOAT32_C(  -778.99), SIMDE_FLOAT32_C(   459.89) } },
      { SIMDE_FLOAT32_C(   936.16), SIMDE_FLOAT32_C(   350.75), SIMDE_FLOAT32_C(  -778.99), SIMDE_FLOAT32_C(   459.89) } },
    {
        { { SIMDE_FLOAT32_C(   642.14), SIMDE_FLOAT32_C(  -227.01) },
          { SIMDE_FLOAT32_C(  -808.03), SIMDE_FLOAT32_C(   325.65) } },
      { SIMDE_FLOAT32_C(   642.14), SIMDE_FLOAT32_C(  -227.01), SIMDE_FLOAT32_C(  -808.03), SIMDE_FLOAT32_C(   325.65) } },
    {
        { { SIMDE_FLOAT32_C(  -493.68), SIMDE_FLOAT32_C(  -172.48) },
          { SIMDE_FLOAT32_C(  -117.53), SIMDE_FLOAT32_C(    43.47) } },
      { SIMDE_FLOAT32_C(  -493.68), SIMDE_FLOAT32_C(  -172.48), SIMDE_FLOAT32_C(  -117.53), SIMDE_FLOAT32_C(    43.47) } },
    {
        { { SIMDE_FLOAT32_C(  -505.19), SIMDE_FLOAT32_C(   -46.35) },
          { SIMDE_FLOAT32_C(  -685.91), SIMDE_FLOAT32_C(   845.53) } },
      { SIMDE_FLOAT32_C(  -505.19), SIMDE_FLOAT32_C(   -46.35), SIMDE_FLOAT32_C(  -685.91), SIMDE_FLOAT32_C(   845.53) } },
    {
        { { SIMDE_FLOAT32_C(    98.78), SIMDE_FLOAT32_C(  -607.16) },
          { SIMDE_FLOAT32_C(   -50.00), SIMDE_FLOAT32_C(   486.94) } },
      { SIMDE_FLOAT32_C(    98.78), SIMDE_FLOAT32_C(  -607.16), SIMDE_FLOAT32_C(   -50.00), SIMDE_FLOAT32_C(   486.94) } },
    {
        { { SIMDE_FLOAT32_C(   338.30), SIMDE_FLOAT32_C(   908.46) },
          { SIMDE_FLOAT32_C(   930.53), SIMDE_FLOAT32_C(   106.71) } },
      { SIMDE_FLOAT32_C(   338.30), SIMDE_FLOAT32_C(   908.46), SIMDE_FLOAT32_C(   930.53), SIMDE_FLOAT32_C(   106.71) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2x2_t r_ = { { simde_vld1_f32(test_vec[i].r[0]),
                                 simde_vld1_f32(test_vec[i].r[1]) } };

    simde_float32 a_[4];
    simde_vst1_f32_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2_t b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f);
    simde_float32x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_f32x2x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    simde_float32 buf[4];
    simde_vst1_f32_x2(buf, c);

    simde_test_codegen_write_vf32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_f64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    simde_float64 r[2][1];
    simde_float64 a[2];
  } test_vec[] = {
    {
        { { SIMDE_FLOAT64_C(   505.61) },
          { SIMDE_FLOAT64_C(   683.86) } },
      { SIMDE_FLOAT64_C(   505.61), SIMDE_FLOAT64_C(   683.86) } },
    {
        { { SIMDE_FLOAT64_C(   764.28) },
          { SIMDE_FLOAT64_C(  -437.62) } },
      { SIMDE_FLOAT64_C(   764.28), SIMDE_FLOAT64_C(  -437.62) } },
    {
        { { SIMDE_FLOAT64_C(    87.32) },
          { SIMDE_FLOAT64_C(   643.18) } },
      { SIMDE_FLOAT64_C(    87.32), SIMDE_FLOAT64_C(   643.18) } },
    {
        { { SIMDE_FLOAT64_C(  -196.43) },
          { SIMDE_FLOAT64_C(    23.48) } },
      { SIMDE_FLOAT64_C(  -196.43), SIMDE_FLOAT64_C(    23.48) } },
    {
        { { SIMDE_FLOAT64_C(    -6.06) },
          { SIMDE_FLOAT64_C(    24.58) } },
      { SIMDE_FLOAT64_C(    -6.06), SIMDE_FLOAT64_C(    24.58) } },
    {
        { { SIMDE_FLOAT64_C(  -516.63) },
          { SIMDE_FLOAT64_C(  -363.92) } },
      { SIMDE_FLOAT64_C(  -516.63), SIMDE_FLOAT64_C(  -363.92) } },
    {
        { { SIMDE_FLOAT64_C(   797.57) },
          { SIMDE_FLOAT64_C(  -324.66) } },
      { SIMDE_FLOAT64_C(   797.57), SIMDE_FLOAT64_C(  -324.66) } },
    {
        { { SIMDE_FLOAT64_C(   961.74) },
          { SIMDE_FLOAT64_C(  -696.12) } },
      { SIMDE_FLOAT64_C(   961.74), SIMDE_FLOAT64_C(  -696.12) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1x2_t r_ = { { simde_vld1_f64(test_vec[i].r[0]),
                                 simde_vld1_f64(test_vec[i].r[1]) } };

    simde_float64 a_[2];
    simde_vst1_f64_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1_t b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0);
    simde_float64x1x2_t c = {{a, b}};

    simde_test_arm_neon_write_f64x1x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    simde_float64 buf[2];
    simde_vst1_f64_x2(buf, c);

    simde_test_codegen_write_vf64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s8_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int8_t r[2][8];
    int8_t a[16];
  } test_vec[] = {
    {
        { {  INT8_C(  52), -INT8_C(  99), -INT8_C(  89), -INT8_C(  70),  INT8_C(  53),  INT8_C(   9),  INT8_C(  49), -INT8_C(  51) },
          { -INT8_C(  68), -INT8_C(  47),  INT8_C( 120), -INT8_C(  17), -INT8_C(  15),  INT8_C(  51), -INT8_C(  89), -INT8_C(  54) } },
      {  INT8_C(  52), -INT8_C(  99), -INT8_C(  89), -INT8_C(  70),  INT8_C(  53),  INT8_C(   9),  INT8_C(  49), -INT8_C(  51),
        -INT8_C(  68), -INT8_C(  47),  INT8_C( 120), -INT8_C(  17), -INT8_C(  15),  INT8_C(  51), -INT8_C(  89), -INT8_C(  54) } },
    {
        { { -INT8_C(  13), -INT8_C( 105),  INT8_C( 108),  INT8_C(  83),  INT8_C(   9), -INT8_C(  18),  INT8_C(  89), -INT8_C(  66) },
          { -INT8_C(  35),  INT8_C(  62),  INT8_C( 115), -INT8_C(  35),  INT8_C( 111), -INT8_C(  68),  INT8_C(  70), -INT8_C(  93) } },
      { -INT8_C(  13), -INT8_C( 105),  INT8_C( 108),  INT8_C(  83),  INT8_C(   9), -INT8_C(  18),  INT8_C(  89), -INT8_C(  66),
        -INT8_C(  35),  INT8_C(  62),  INT8_C( 115), -INT8_C(  35),  INT8_C( 111), -INT8_C(  68),  INT8_C(  70), -INT8_C(  93) } },
    {
        { {  INT8_C(  89), -INT8_C(  19),  INT8_C(  93), -INT8_C( 114), -INT8_C(  10), -INT8_C( 113),  INT8_C(  92), -INT8_C(  77) },
          {  INT8_C(  96), -INT8_C(  44), -INT8_C(  94),  INT8_C(  81),  INT8_C(   7),  INT8_C(  73),  INT8_C(  28), -INT8_C(   5) } },
      {  INT8_C(  89), -INT8_C(  19),  INT8_C(  93), -INT8_C( 114), -INT8_C(  10), -INT8_C( 113),  INT8_C(  92), -INT8_C(  77),
         INT8_C(  96), -INT8_C(  44), -INT8_C(  94),  INT8_C(  81),  INT8_C(   7),  INT8_C(  73),  INT8_C(  28), -INT8_C(   5) } },
    {
        { { -INT8_C(  32), -INT8_C( 120),  INT8_C(  78), -INT8_C(  23),  INT8_C( 118), -INT8_C(  89), -INT8_C(  88),  INT8_C(  83) },
          { -INT8_C(  26),  INT8_C(  27),  INT8_C(  49),  INT8_C(  85), -INT8_C(  41),  INT8_C( 119), -INT8_C(   8),  INT8_C(  48) } },
      { -INT8_C(  32), -INT8_C( 120),  INT8_C(  78), -INT8_C(  23),  INT8_C( 118), -INT8_C(  89), -INT8_C(  88),  INT8_C(  83),
        -INT8_C(  26),  INT8_C(  27),  INT8_C(  49),  INT8_C(  85), -INT8_C(  41),  INT8_C( 119), -INT8_C(   8),  INT8_C(  48) } },
    {
        { {  INT8_C( 100),  INT8_C(  85), -INT8_C(  66),  INT8_C(  90), -INT8_C(  28),  INT8_C(  26),  INT8_C(  13),  INT8_C(  69) },
          { -INT8_C(  18), -INT8_C(  81), -INT8_C( 106), -INT8_C(  10), -INT8_C(   8), -INT8_C(  78), -INT8_C(  15), -INT8_C(  40) } },
      {  INT8_C( 100),  INT8_C(  85), -INT8_C(  66),  INT8_C(  90), -INT8_C(  28),  INT8_C(  26),  INT8_C(  13),  INT8_C(  69),
        -INT8_C(  18), -INT8_C(  81), -INT8_C( 106), -INT8_C(  10), -INT8_C(   8), -INT8_C(  78), -INT8_C(  15), -INT8_C(  40) } },
    {
        { {  INT8_C(  58),  INT8_C(  63), -INT8_C(  62), -INT8_C(  79), -INT8_C(  26),  INT8_C( 106),  INT8_C(   4), -INT8_C(  52) },
          { -INT8_C( 123),  INT8_C(  53),  INT8_C(  33),  INT8_C(  92), -INT8_C(  84),  INT8_C(  25), -INT8_C( 116),  INT8_C(  16) } },
      {  INT8_C(  58),  INT8_C(  63), -INT8_C(  62), -INT8_C(  79), -INT8_C(  26),  INT8_C( 106),  INT8_C(   4), -INT8_C(  52),
        -INT8_C( 123),  INT8_C(  53),  INT8_C(  33),  INT8_C(  92), -INT8_C(  84),  INT8_C(  25), -INT8_C( 116),  INT8_C(  16) } },
    {
        { {  INT8_C( 111),  INT8_C(  74),  INT8_C( 107),  INT8_C(  83),  INT8_C( 101),  INT8_C( 120), -INT8_C( 104),  INT8_C(  83) },
          {  INT8_C(  40),  INT8_C(  47),  INT8_C(  73),  INT8_C(  32), -INT8_C(  31),  INT8_C(  58), -INT8_C(   7),  INT8_C(  28) } },
      {  INT8_C( 111),  INT8_C(  74),  INT8_C( 107),  INT8_C(  83),  INT8_C( 101),  INT8_C( 120), -INT8_C( 104),  INT8_C(  83),
         INT8_C(  40),  INT8_C(  47),  INT8_C(  73),  INT8_C(  32), -INT8_C(  31),  INT8_C(  58), -INT8_C(   7),  INT8_C(  28) } },
    {
        { {  INT8_C( 121), -INT8_C(  69), -INT8_C(  51),  INT8_C(  96),  INT8_C(  37), -INT8_C(  47),  INT8_C(  44), -INT8_C(  86) },
          {  INT8_C(   7),  INT8_C(  78),  INT8_C(   6), -INT8_C(  77),  INT8_C( 103), -INT8_C( 110), -INT8_C(  60), -INT8_C(  42) } },
      {  INT8_C( 121), -INT8_C(  69), -INT8_C(  51),  INT8_C(  96),  INT8_C(  37), -INT8_C(  47),  INT8_C(  44), -INT8_C(  86),
         INT8_C(   7),  INT8_C(  78),  INT8_C(   6), -INT8_C(  77),  INT8_C( 103), -INT8_C( 110), -INT8_C(  60), -INT8_C(  42) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8x2_t r_ = { { simde_vld1_s8(test_vec[i].r[0]),
                              simde_vld1_s8(test_vec[i].r[1]) } };

    int8_t a_[16];
    simde_vst1_s8_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t a = simde_test_arm_neon_random_i8x8();
    simde_int8x8_t b = simde_test_arm_neon_random_i8x8();
    simde_int8x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_i8x8x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    int8_t buf[16];
    simde_vst1_s8_x2(buf, c);

    simde_test_codegen_write_vi8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int16_t r[2][4];
    int16_t a[8];
  } test_vec[] = {
    {
        { {  INT16_C( 12252),  INT16_C( 16682), -INT16_C( 15705), -INT16_C( 12395) },
          { -INT16_C(  8463), -INT16_C( 11280), -INT16_C(  5863), -INT16_C( 27921) } },
      {  INT16_C( 12252),  INT16_C( 16682), -INT16_C( 15705), -INT16_C( 12395), -INT16_C(  8463), -INT16_C( 11280), -INT16_C(  5863), -INT16_C( 27921) } },
    {
        { { -INT16_C( 17244), -INT16_C( 13838),  INT16_C(  8077), -INT16_C( 27533) },
          {  INT16_C( 31085), -INT16_C( 11192),  INT16_C(  3083), -INT16_C(  6229) } },
      { -INT16_C( 17244), -INT16_C( 13838),  INT16_C(  8077), -INT16_C( 27533),  INT16_C( 31085), -INT16_C( 11192),  INT16_C(  3083), -INT16_C(  6229) } },
    {
        { { -INT16_C( 10949), -INT16_C(  7639), -INT16_C( 16745), -INT16_C( 30286) },
          { -INT16_C( 23908), -INT16_C( 19108),  INT16_C( 19339),  INT16_C( 12104) } },
      { -INT16_C( 10949), -INT16_C(  7639), -INT16_C( 16745), -INT16_C( 30286), -INT16_C( 23908), -INT16_C( 19108),  INT16_C( 19339),  INT16_C( 12104) } },
    {
        { {  INT16_C( 14855), -INT16_C( 27400),  INT16_C( 27481), -INT16_C( 14807) },
          {  INT16_C( 29156), -INT16_C(  4197),  INT16_C( 18045), -INT16_C( 18218) } },
      {  INT16_C( 14855), -INT16_C( 27400),  INT16_C( 27481), -INT16_C( 14807),  INT16_C( 29156), -INT16_C(  4197),  INT16_C( 18045), -INT16_C( 18218) } },
    {
        { { -INT16_C(   229), -INT16_C( 19814),  INT16_C( 19645),  INT16_C( 23099) },
          { -INT16_C( 26642),  INT16_C( 30991),  INT16_C( 22498), -INT16_C(  5720) } },
      { -INT16_C(   229), -INT16_C( 19814),  INT16_C( 19645),  INT16_C( 23099), -INT16_C( 26642),  INT16_C( 30991),  INT16_C( 22498), -INT16_C(  5720) } },
    {
        { { -INT16_C( 24430), -INT16_C(  5250), -INT16_C( 22773), -INT16_C(  4174) },
          {  INT16_C( 19736), -INT16_C( 27170), -INT16_C( 19053), -INT16_C( 20915) } },
      { -INT16_C( 24430), -INT16_C(  5250), -INT16_C( 22773), -INT16_C(  4174),  INT16_C( 19736), -INT16_C( 27170), -INT16_C( 19053), -INT16_C( 20915) } },
    {
        { { -INT16_C(  6220),  INT16_C( 29280), -INT16_C( 25548),  INT16_C(  8908) },
          { -INT16_C(  9421),  INT16_C(  5788),  INT16_C( 17459), -INT16_C( 14849) } },
      { -INT16_C(  6220),  INT16_C( 29280), -INT16_C( 25548),  INT16_C(  8908), -INT16_C(  9421),  INT16_C(  5788),  INT16_C( 17459), -INT16_C( 14849) } },
    {
        { {  INT16_C( 32229), -INT16_C(  3920),  INT16_C( 25124),  INT16_C( 15584) },
          { -INT16_C( 16721),  INT16_C( 17105),  INT16_C(  7795),  INT16_C( 10480) } },
      {  INT16_C( 32229), -INT16_C(  3920),  INT16_C( 25124),  INT16_C( 15584), -INT16_C( 16721),  INT16_C( 17105),  INT16_C(  7795),  INT16_C( 10480) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4x2_t r_ = { { simde_vld1_s16(test_vec[i].r[0]),
                               simde_vld1_s16(test_vec[i].r[1]) } };

    int16_t a_[8];
    simde_vst1_s16_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t a = simde_test_arm_neon_random_i16x4();
    simde_int16x4_t b = simde_test_arm_neon_random_i16x4();
    simde_int16x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_i16x4x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    int16_t buf[8];
    simde_vst1_s16_x2(buf, c);

    simde_test_codegen_write_vi16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int32_t r[2][2];
    int32_t a[4];
  } test_vec[] = {
    {
        { {  INT32_C(   983191814),  INT32_C(   542926573) },
          {  INT32_C(  1949759553),  INT32_C(   574174781) } },
      {  INT32_C(   983191814),  INT32_C(   542926573),  INT32_C(  1949759553),  INT32_C(   574174781) } },
    {
        { { -INT32_C(   669848909), -INT32_C(    65736116) },
          {  INT32_C(   608102065),  INT32_C(   172764932) } },
      { -INT32_C(   669848909), -INT32_C(    65736116),  INT32_C(   608102065),  INT32_C(   172764932) } },
    {
        { {  INT32_C(  1833232000), -INT32_C(  1903320756) },
          { -INT32_C(   704461671), -INT32_C(  1376240390) } },
      {  INT32_C(  1833232000), -INT32_C(  1903320756), -INT32_C(   704461671), -INT32_C(  1376240390) } },
    {
        { {  INT32_C(  1921321766), -INT32_C(  1368483075) },
          { -INT32_C(  2066502272),  INT32_C(  1552883676) } },
      {  INT32_C(  1921321766), -INT32_C(  1368483075), -INT32_C(  2066502272),  INT32_C(  1552883676) } },
    {
        { {  INT32_C(  1388958470),  INT32_C(   249583220) },
          {  INT32_C(   350544666),  INT32_C(  1170398495) } },
      {  INT32_C(  1388958470),  INT32_C(   249583220),  INT32_C(   350544666),  INT32_C(  1170398495) } },
    {
        { { -INT32_C(   440973336),  INT32_C(  1637099233) },
          { -INT32_C(  1343854637), -INT32_C(  1945406074) } },
      { -INT32_C(   440973336),  INT32_C(  1637099233), -INT32_C(  1343854637), -INT32_C(  1945406074) } },
    {
        { { -INT32_C(  1109404600),  INT32_C(  1170980650) },
          { -INT32_C(  1051086942),  INT32_C(  1946557324) } },
      { -INT32_C(  1109404600),  INT32_C(  1170980650), -INT32_C(  1051086942),  INT32_C(  1946557324) } },
    {
        { {  INT32_C(  1146797667), -INT32_C(  1213796636) },
          { -INT32_C(   614036395),  INT32_C(  1231581441) } },
      {  INT32_C(  1146797667), -INT32_C(  1213796636), -INT32_C(   614036395),  INT32_C(  1231581441) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2x2_t r_ = { { simde_vld1_s32(test_vec[i].r[0]),
                               simde_vld1_s32(test_vec[i].r[1]) } };

    int32_t a_[4];
    simde_vst1_s32_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t a = simde_test_arm_neon_random_i32x2();
    simde_int32x2_t b = simde_test_arm_neon_random_i32x2();
    simde_int32x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_i32x2x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    int32_t buf[4];
    simde_vst1_s32_x2(buf, c);

    simde_test_codegen_write_vi32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_s64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    int64_t r[2][1];
    int64_t a[2];
  } test_vec[] = {
    {
        { { -INT64_C( 6218115359929120955) },
          { -INT64_C( 8321964740294603135) } },
      { -INT64_C( 6218115359929120955), -INT64_C( 8321964740294603135) } },
    {
        { {  INT64_C( 2290775070270938159) },
          { -INT64_C( 1851715428066643965) } },
      {  INT64_C( 2290775070270938159), -INT64_C( 1851715428066643965) } },
    {
        { { -INT64_C( 6460121033497815895) },
          {  INT64_C( 7191745253025825560) } },
      { -INT64_C( 6460121033497815895),  INT64_C( 7191745253025825560) } },
    {
        { {  INT64_C( 1872160537034792722) },
          {  INT64_C(  141698839762302320) } },
      {  INT64_C( 1872160537034792722),  INT64_C(  141698839762302320) } },
    {
        { {  INT64_C( 8037247857611328958) },
          { -INT64_C( 8762176988276310322) } },
      {  INT64_C( 8037247857611328958), -INT64_C( 8762176988276310322) } },
    {
        { { -INT64_C( 8265128836134151139) },
          { -INT64_C( 7877755808021255853) } },
      { -INT64_C( 8265128836134151139), -INT64_C( 7877755808021255853) } },
    {
        { {  INT64_C( 3938680896281272035) },
          { -INT64_C(  704074638644651457) } },
      {  INT64_C( 3938680896281272035), -INT64_C(  704074638644651457) } },
    {
        { {  INT64_C( 5559261608702221691) },
          {  INT64_C( 4559513486039238111) } },
      {  INT64_C( 5559261608702221691),  INT64_C( 4559513486039238111) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1x2_t r_ = { { simde_vld1_s64(test_vec[i].r[0]),
                               simde_vld1_s64(test_vec[i].r[1]) } };

    int64_t a_[2];
    simde_vst1_s64_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t a = simde_test_arm_neon_random_i64x1();
    simde_int64x1_t b = simde_test_arm_neon_random_i64x1();
    simde_int64x1x2_t c = {{a, b}};

    simde_test_arm_neon_write_i64x1x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    int64_t buf[2];
    simde_vst1_s64_x2(buf, c);

    simde_test_codegen_write_vi64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u8_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint8_t r[2][8];
    uint8_t a[16];
  } test_vec[] = {
    {
        { { UINT8_C(230), UINT8_C( 67), UINT8_C( 45), UINT8_C(189), UINT8_C(130), UINT8_C( 30), UINT8_C( 47), UINT8_C(189) },
          { UINT8_C( 73), UINT8_C(156), UINT8_C( 80), UINT8_C(165), UINT8_C(146), UINT8_C( 90), UINT8_C( 22), UINT8_C( 30) } },
      { UINT8_C(230), UINT8_C( 67), UINT8_C( 45), UINT8_C(189), UINT8_C(130), UINT8_C( 30), UINT8_C( 47), UINT8_C(189),
        UINT8_C( 73), UINT8_C(156), UINT8_C( 80), UINT8_C(165), UINT8_C(146), UINT8_C( 90), UINT8_C( 22), UINT8_C( 30) } },
    {
        { { UINT8_C( 80), UINT8_C(137), UINT8_C(  8), UINT8_C(236), UINT8_C( 28), UINT8_C(181), UINT8_C(124), UINT8_C(  1) },
          { UINT8_C( 25), UINT8_C( 98), UINT8_C(112), UINT8_C( 11), UINT8_C(184), UINT8_C(206), UINT8_C(100), UINT8_C(158) } },
      { UINT8_C( 80), UINT8_C(137), UINT8_C(  8), UINT8_C(236), UINT8_C( 28), UINT8_C(181), UINT8_C(124), UINT8_C(  1),
        UINT8_C( 25), UINT8_C( 98), UINT8_C(112), UINT8_C( 11), UINT8_C(184), UINT8_C(206), UINT8_C(100), UINT8_C(158) } },
    {
        { { UINT8_C( 17), UINT8_C(145), UINT8_C( 91), UINT8_C(147), UINT8_C(175), UINT8_C(139), UINT8_C( 80), UINT8_C(249) },
          { UINT8_C( 39), UINT8_C(161), UINT8_C(158), UINT8_C(185), UINT8_C(251), UINT8_C(181), UINT8_C(216), UINT8_C( 75) } },
      { UINT8_C( 17), UINT8_C(145), UINT8_C( 91), UINT8_C(147), UINT8_C(175), UINT8_C(139), UINT8_C( 80), UINT8_C(249),
        UINT8_C( 39), UINT8_C(161), UINT8_C(158), UINT8_C(185), UINT8_C(251), UINT8_C(181), UINT8_C(216), UINT8_C( 75) } },
    {
        { { UINT8_C( 62), UINT8_C(224), UINT8_C( 55), UINT8_C( 90), UINT8_C(149), UINT8_C(180), UINT8_C( 91), UINT8_C(174) },
          { UINT8_C( 22), UINT8_C(203), UINT8_C(186), UINT8_C(206), UINT8_C(153), UINT8_C( 30), UINT8_C(109), UINT8_C(170) } },
      { UINT8_C( 62), UINT8_C(224), UINT8_C( 55), UINT8_C( 90), UINT8_C(149), UINT8_C(180), UINT8_C( 91), UINT8_C(174),
        UINT8_C( 22), UINT8_C(203), UINT8_C(186), UINT8_C(206), UINT8_C(153), UINT8_C( 30), UINT8_C(109), UINT8_C(170) } },
    {
        { { UINT8_C(175), UINT8_C(200), UINT8_C( 61), UINT8_C( 94), UINT8_C( 83), UINT8_C(142), UINT8_C( 87), UINT8_C(122) },
          { UINT8_C( 47), UINT8_C(246), UINT8_C( 52), UINT8_C( 42), UINT8_C(171), UINT8_C( 12), UINT8_C(117), UINT8_C(233) } },
      { UINT8_C(175), UINT8_C(200), UINT8_C( 61), UINT8_C( 94), UINT8_C( 83), UINT8_C(142), UINT8_C( 87), UINT8_C(122),
        UINT8_C( 47), UINT8_C(246), UINT8_C( 52), UINT8_C( 42), UINT8_C(171), UINT8_C( 12), UINT8_C(117), UINT8_C(233) } },
    {
        { { UINT8_C(236), UINT8_C(173), UINT8_C( 67), UINT8_C(129), UINT8_C( 97), UINT8_C(158), UINT8_C( 47), UINT8_C(119) },
          { UINT8_C(106), UINT8_C(233), UINT8_C( 70), UINT8_C(  3), UINT8_C(  7), UINT8_C(179), UINT8_C(174), UINT8_C(182) } },
      { UINT8_C(236), UINT8_C(173), UINT8_C( 67), UINT8_C(129), UINT8_C( 97), UINT8_C(158), UINT8_C( 47), UINT8_C(119),
        UINT8_C(106), UINT8_C(233), UINT8_C( 70), UINT8_C(  3), UINT8_C(  7), UINT8_C(179), UINT8_C(174), UINT8_C(182) } },
    {
        { { UINT8_C(123), UINT8_C(235), UINT8_C( 21), UINT8_C(207), UINT8_C(121), UINT8_C(108), UINT8_C( 73), UINT8_C(168) },
          { UINT8_C( 98), UINT8_C(125), UINT8_C(210), UINT8_C( 13), UINT8_C(137), UINT8_C( 72), UINT8_C(246), UINT8_C(117) } },
      { UINT8_C(123), UINT8_C(235), UINT8_C( 21), UINT8_C(207), UINT8_C(121), UINT8_C(108), UINT8_C( 73), UINT8_C(168),
        UINT8_C( 98), UINT8_C(125), UINT8_C(210), UINT8_C( 13), UINT8_C(137), UINT8_C( 72), UINT8_C(246), UINT8_C(117) } },
    {
        { { UINT8_C(245), UINT8_C( 57), UINT8_C(246), UINT8_C( 86), UINT8_C(216), UINT8_C( 38), UINT8_C(205), UINT8_C( 66) },
          { UINT8_C( 15), UINT8_C( 19), UINT8_C( 69), UINT8_C( 23), UINT8_C(198), UINT8_C(243), UINT8_C(205), UINT8_C( 66) } },
      { UINT8_C(245), UINT8_C( 57), UINT8_C(246), UINT8_C( 86), UINT8_C(216), UINT8_C( 38), UINT8_C(205), UINT8_C( 66),
        UINT8_C( 15), UINT8_C( 19), UINT8_C( 69), UINT8_C( 23), UINT8_C(198), UINT8_C(243), UINT8_C(205), UINT8_C( 66) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint8x8x2_t r_ = { { simde_vld1_u8(test_vec[i].r[0]),
                               simde_vld1_u8(test_vec[i].r[1]) } };

    uint8_t a_[16];
    simde_vst1_u8_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint8x8_t a = simde_test_arm_neon_random_u8x8();
    simde_uint8x8_t b = simde_test_arm_neon_random_u8x8();
    simde_uint8x8x2_t c = {{a, b}};

    simde_test_arm_neon_write_u8x8x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    uint8_t buf[16];
    simde_vst1_u8_x2(buf, c);

    simde_test_codegen_write_vu8(2, sizeof(buf) / sizeof(buf[0]), buf,
                                 SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u16_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint16_t r[2][4];
    uint16_t a[8];
  } test_vec[] = {
    {
        { { UINT16_C( 5790), UINT16_C(32356), UINT16_C(38547), UINT16_C(48772) },
          { UINT16_C(18976), UINT16_C(  882), UINT16_C(13574), UINT16_C(13707) } },
      { UINT16_C( 5790), UINT16_C(32356), UINT16_C(38547), UINT16_C(48772), UINT16_C(18976), UINT16_C(  882), UINT16_C(13574), UINT16_C(13707) } },
    {
        { { UINT16_C(47046), UINT16_C(12838), UINT16_C(35580), UINT16_C(36186) },
          { UINT16_C(30369), UINT16_C(42558), UINT16_C(38313), UINT16_C(18297) } },
      { UINT16_C(47046), UINT16_C(12838), UINT16_C(35580), UINT16_C(36186), UINT16_C(30369), UINT16_C(42558), UINT16_C(38313), UINT16_C(18297) } },
    {
        { { UINT16_C(56747), UINT16_C(16326), UINT16_C(19059), UINT16_C(37885) },
          { UINT16_C(28564), UINT16_C(39574), UINT16_C( 8612), UINT16_C(27344) } },
      { UINT16_C(56747), UINT16_C(16326), UINT16_C(19059), UINT16_C(37885), UINT16_C(28564), UINT16_C(39574), UINT16_C( 8612), UINT16_C(27344) } },
    {
        { { UINT16_C(63192), UINT16_C(54685), UINT16_C(63360), UINT16_C( 8546) },
          { UINT16_C(41069), UINT16_C( 6088), UINT16_C(16694), UINT16_C(57694) } },
      { UINT16_C(63192), UINT16_C(54685), UINT16_C(63360), UINT16_C( 8546), UINT16_C(41069), UINT16_C( 6088), UINT16_C(16694), UINT16_C(57694) } },
    {
        { { UINT16_C( 9246), UINT16_C(37408), UINT16_C( 7534), UINT16_C(  805) },
          { UINT16_C(48269), UINT16_C(12701), UINT16_C(28125), UINT16_C(46748) } },
      { UINT16_C( 9246), UINT16_C(37408), UINT16_C( 7534), UINT16_C(  805), UINT16_C(48269), UINT16_C(12701), UINT16_C(28125), UINT16_C(46748) } },
    {
        { { UINT16_C(14691), UINT16_C(58251), UINT16_C(60720), UINT16_C(40197) },
          { UINT16_C(52622), UINT16_C(50356), UINT16_C( 4878), UINT16_C(11429) } },
      { UINT16_C(14691), UINT16_C(58251), UINT16_C(60720), UINT16_C(40197), UINT16_C(52622), UINT16_C(50356), UINT16_C( 4878), UINT16_C(11429) } },
    {
        { { UINT16_C(50743), UINT16_C(42686), UINT16_C(58595), UINT16_C(28841) },
          { UINT16_C(18080), UINT16_C(32162), UINT16_C(16052), UINT16_C( 5939) } },
      { UINT16_C(50743), UINT16_C(42686), UINT16_C(58595), UINT16_C(28841), UINT16_C(18080), UINT16_C(32162), UINT16_C(16052), UINT16_C( 5939) } },
    {
        { { UINT16_C(48759), UINT16_C(43003), UINT16_C(  172), UINT16_C(14916) },
          { UINT16_C(63949), UINT16_C(56318), UINT16_C(41740), UINT16_C(17159) } },
      { UINT16_C(48759), UINT16_C(43003), UINT16_C(  172), UINT16_C(14916), UINT16_C(63949), UINT16_C(56318), UINT16_C(41740), UINT16_C(17159) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint16x4x2_t r_ = { { simde_vld1_u16(test_vec[i].r[0]),
                                simde_vld1_u16(test_vec[i].r[1]) } };

    uint16_t a_[8];
    simde_vst1_u16_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint16x4_t a = simde_test_arm_neon_random_u16x4();
    simde_uint16x4_t b = simde_test_arm_neon_random_u16x4();
    simde_uint16x4x2_t c = {{a, b}};

    simde_test_arm_neon_write_u16x4x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    uint16_t buf[8];
    simde_vst1_u16_x2(buf, c);

    simde_test_codegen_write_vu16(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u32_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint32_t r[2][2];
    uint32_t a[4];
  } test_vec[] = {
    {
        { { UINT32_C(1307166313), UINT32_C(1253937834) },
          { UINT32_C(2378653657), UINT32_C( 346356637) } },
      { UINT32_C(1307166313), UINT32_C(1253937834), UINT32_C(2378653657), UINT32_C( 346356637) } },
    {
        { { UINT32_C(1706794937), UINT32_C(1822359711) },
          { UINT32_C(  88579577), UINT32_C(2856865601) } },
      { UINT32_C(1706794937), UINT32_C(1822359711), UINT32_C(  88579577), UINT32_C(2856865601) } },
    {
        { { UINT32_C(3220648469), UINT32_C(2634659268) },
          { UINT32_C(2989150228), UINT32_C(2244399051) } },
      { UINT32_C(3220648469), UINT32_C(2634659268), UINT32_C(2989150228), UINT32_C(2244399051) } },
    {
        { { UINT32_C( 250249838), UINT32_C(2071628418) },
          { UINT32_C(1753268775), UINT32_C( 638830609) } },
      { UINT32_C( 250249838), UINT32_C(2071628418), UINT32_C(1753268775), UINT32_C( 638830609) } },
    {
        { { UINT32_C(3219458810), UINT32_C(3562860223) },
          { UINT32_C(2324072382), UINT32_C(3289336918) } },
      { UINT32_C(3219458810), UINT32_C(3562860223), UINT32_C(2324072382), UINT32_C(3289336918) } },
    {
        { { UINT32_C(1356003790), UINT32_C(2882227587) },
          { UINT32_C( 538135311), UINT32_C( 239478292) } },
      { UINT32_C(1356003790), UINT32_C(2882227587), UINT32_C( 538135311), UINT32_C( 239478292) } },
    {
        { { UINT32_C(4039977777), UINT32_C(3619957273) },
          { UINT32_C( 123816625), UINT32_C(1707831447) } },
      { UINT32_C(4039977777), UINT32_C(3619957273), UINT32_C( 123816625), UINT32_C(1707831447) } },
    {
        { { UINT32_C(3988168298), UINT32_C(4204298731) },
          { UINT32_C(3776621773), UINT32_C(  66019538) } },
      { UINT32_C(3988168298), UINT32_C(4204298731), UINT32_C(3776621773), UINT32_C(  66019538) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint32x2x2_t r_ = { { simde_vld1_u32(test_vec[i].r[0]),
                                simde_vld1_u32(test_vec[i].r[1]) } };

    uint32_t a_[4];
    simde_vst1_u32_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint32x2_t a = simde_test_arm_neon_random_u32x2();
    simde_uint32x2_t b = simde_test_arm_neon_random_u32x2();
    simde_uint32x2x2_t c = {{a, b}};

    simde_test_arm_neon_write_u32x2x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    uint32_t buf[4];
    simde_vst1_u32_x2(buf, c);

    simde_test_codegen_write_vu32(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

static int
test_simde_vst1_u64_x2 (SIMDE_MUNIT_TEST_ARGS) {
#if 1
  static const struct {
    uint64_t r[2][1];
    uint64_t a[2];
  } test_vec[] = {
    {
        { { UINT64_C(10987579020944915851) },
          { UINT64_C(13258432709541223683) } },
      { UINT64_C(10987579020944915851), UINT64_C(13258432709541223683) } },
    {
        { { UINT64_C(  355007256152356104) },
          { UINT64_C(17491933019746142185) } },
      { UINT64_C(  355007256152356104), UINT64_C(17491933019746142185) } },
    {
        { { UINT64_C( 8002916794926281617) },
          { UINT64_C( 2518647000376389615) } },
      { UINT64_C( 8002916794926281617), UINT64_C( 2518647000376389615) } },
    {
        { { UINT64_C(13905149546252900798) },
          { UINT64_C( 4928411004837879307) } },
      { UINT64_C(13905149546252900798), UINT64_C( 4928411004837879307) } },
    {
        { { UINT64_C(18215597100110773231) },
          { UINT64_C(11076935179635905404) } },
      { UINT64_C(18215597100110773231), UINT64_C(11076935179635905404) } },
    {
        { { UINT64_C(15950773318878941126) },
          { UINT64_C(  242267577883088997) } },
      { UINT64_C(15950773318878941126), UINT64_C(  242267577883088997) } },
    {
        { { UINT64_C( 7114043528591579312) },
          { UINT64_C(16604966580718728187) } },
      { UINT64_C( 7114043528591579312), UINT64_C(16604966580718728187) } },
    {
        { { UINT64_C(16947291165814947456) },
          { UINT64_C(16631616633563218104) } },
      { UINT64_C(16947291165814947456), UINT64_C(16631616633563218104) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_uint64x1x2_t r_ = { { simde_vld1_u64(test_vec[i].r[0]),
                                simde_vld1_u64(test_vec[i].r[1]) } };

    uint64_t a_[2];
    simde_vst1_u64_x2(a_, r_);

    simde_assert_equal_i(0, simde_memcmp(a_, test_vec[i].a, sizeof(test_vec[i].a)));
  }

  return 0;
#else
  for (int i = 0 ; i < 8 ; i++) {
    simde_uint64x1_t a = simde_test_arm_neon_random_u64x1();
    simde_uint64x1_t b = simde_test_arm_neon_random_u64x1();
    simde_uint64x1x2_t c = {{a, b}};

    simde_test_arm_neon_write_u64x1x2(2, c, SIMDE_TEST_VEC_POS_FIRST);

    uint64_t buf[2];
    simde_vst1_u64_x2(buf, c);

    simde_test_codegen_write_vu64(2, sizeof(buf) / sizeof(buf[0]), buf,
                                  SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
#endif
}

#endif /* !defined(SIMDE_BUG_INTEL_857088) */

SIMDE_TEST_FUNC_LIST_BEGIN
#if !defined(SIMDE_BUG_INTEL_857088)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_f64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_s64_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u8_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u16_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u32_x2)
SIMDE_TEST_FUNC_LIST_ENTRY(vst1_u64_x2)
#endif /* !defined(SIMDE_BUG_INTEL_857088) */
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
