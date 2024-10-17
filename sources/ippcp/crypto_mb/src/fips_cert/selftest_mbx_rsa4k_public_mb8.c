/*************************************************************************
* Copyright (C) 2023 Intel Corporation
*
* Licensed under the Apache License,  Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* 	http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law  or agreed  to  in  writing,  software
* distributed under  the License  is  distributed  on  an  "AS IS"  BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the  specific  language  governing  permissions  and
* limitations under the License.
*************************************************************************/
#ifdef MBX_FIPS_MODE

#include <crypto_mb/fips_cert.h>
#include <internal/fips_cert/common.h>
#include <internal/rsa/ifma_rsa_method.h>

#include <crypto_mb/rsa.h>

/* KAT TEST (generated via internal tests) */
/* moduli */
static const int8u moduli[MBX_RSA4K_DATA_BYTE_LEN] = {
  0x6b,0x7c,0x69,0xa3,0x81,0x3e,0x78,0x45,0x97,0xf3,0xe6,0x64,0xf7,0x65,0xc4,0xf2,
  0xa4,0x25,0x58,0x5d,0x2e,0xaf,0x09,0xaf,0x7a,0x96,0x04,0xb0,0x6f,0xf2,0xfb,0xc0,
  0xf7,0x5d,0x0a,0x1b,0x76,0x3c,0xf2,0xb4,0xa0,0x45,0xce,0xc1,0x6c,0x56,0xb0,0x98,
  0x88,0x51,0x27,0x57,0x7e,0xe4,0x6e,0x45,0x73,0x4a,0x2b,0x39,0x6a,0x35,0x05,0xd9,
  0xc6,0x15,0xee,0x26,0xac,0xb2,0x3f,0xa6,0xef,0x21,0x91,0x36,0xbd,0x24,0x60,0xa9,
  0x55,0xb2,0x6f,0xa8,0x1a,0xca,0x44,0xe8,0xaa,0xf7,0x80,0xb2,0x31,0x1a,0x8c,0x52,
  0x97,0xe7,0x8c,0xb7,0x28,0xdb,0x6c,0x79,0x99,0x4e,0xfc,0x1c,0xa9,0x7b,0xa9,0x06,
  0x03,0xfe,0x0c,0xc5,0x75,0x19,0xc5,0xc5,0xf1,0xd0,0x3f,0xea,0xb8,0x59,0x79,0x26,
  0x86,0xc8,0xe9,0xa0,0x99,0xc1,0x24,0x72,0xed,0x82,0xc4,0x7a,0x8a,0x07,0x57,0x40,
  0xc3,0xcb,0xb3,0x71,0x34,0x5d,0x39,0x30,0xb2,0xbc,0x5b,0x95,0xc8,0x44,0x07,0xb4,
  0x3a,0xfe,0xf4,0xd8,0xb3,0xd5,0xe8,0x2a,0x23,0xc0,0x35,0xc5,0xeb,0x46,0x79,0x29,
  0xab,0xe8,0xf8,0x15,0x2c,0xf9,0x36,0xa6,0xa7,0xdb,0x60,0xd1,0x05,0xd2,0x4a,0xbd,
  0x48,0xc4,0x6d,0xe3,0x50,0x56,0x7d,0x7e,0xf2,0x57,0xb1,0x0d,0xfd,0x22,0x2d,0x0f,
  0x4d,0x39,0xc6,0x23,0x70,0x68,0x01,0xb8,0xd0,0xee,0xfa,0xa3,0x5e,0x7a,0xe5,0x0a,
  0x11,0x28,0xb8,0x99,0x59,0xcd,0x0e,0x3f,0x79,0x95,0x98,0xa8,0x60,0x36,0x62,0x34,
  0x97,0xd0,0x51,0x5c,0x46,0x65,0x15,0xd6,0x81,0x4d,0xf8,0x70,0xb2,0x49,0xad,0xd1,
  0x50,0xd8,0xc9,0x9d,0x22,0xf2,0xe7,0xef,0x6b,0x59,0xc7,0x9d,0xc8,0x54,0x86,0xbc,
  0x10,0x6e,0x7d,0x20,0xad,0xf4,0xab,0x9c,0xd8,0x48,0xa4,0x01,0xa4,0x75,0x1f,0xd7,
  0x18,0x0d,0x4f,0x87,0x3d,0xc5,0x86,0xbe,0x50,0xd2,0x22,0xc8,0x55,0xc6,0xa3,0xff,
  0x1c,0x7f,0x9c,0x4d,0xeb,0x29,0x4e,0xbb,0xd2,0xbd,0x7d,0x3d,0x8b,0xc5,0xef,0x6d,
  0x1d,0x2f,0x27,0x46,0x57,0xb7,0xf8,0xe0,0x0c,0x2e,0xe4,0x17,0x4e,0x87,0x83,0xe5,
  0x2a,0x0b,0x0c,0x3f,0x6f,0xce,0x16,0x64,0x2b,0xff,0x8a,0xaa,0xdd,0xdc,0x3e,0x12,
  0xba,0x2d,0xa1,0x71,0xcc,0x70,0xc2,0x05,0x86,0x3a,0x4a,0x4b,0x7c,0x07,0x96,0xb2,
  0x5c,0x2d,0xe7,0x56,0x8e,0xdf,0x5e,0x80,0x6e,0x6f,0xde,0x0c,0x4c,0x5e,0x5a,0x61,
  0x5c,0x77,0xef,0x3f,0x8d,0x14,0x89,0xe2,0x4e,0x36,0xa6,0x6a,0x0c,0x3c,0x6b,0x79,
  0x4b,0xe0,0x62,0x78,0xcb,0x10,0x18,0x96,0x6c,0xdd,0x6c,0x90,0xc0,0xc5,0xc3,0xbb,
  0x67,0x56,0x5c,0xf2,0xec,0x68,0x4e,0xae,0x29,0xbc,0x06,0x08,0x1f,0x0b,0x5a,0x49,
  0xb8,0x02,0xf8,0x6e,0x4b,0xa0,0xe1,0xdd,0xc1,0xb0,0xaa,0xd0,0x8c,0x71,0x72,0x69,
  0xa3,0xf6,0x3b,0xc8,0x45,0x38,0xef,0xbf,0xc8,0x75,0x3c,0xc8,0xe5,0xd1,0xac,0x9c,
  0xda,0xb3,0xe9,0x7c,0xde,0x38,0x96,0xc4,0x1d,0x29,0xf6,0x80,0x4d,0x4b,0x0e,0xf2,
  0x46,0x5f,0x2d,0x3d,0x1b,0xc2,0x7a,0xc6,0xa9,0xa5,0xb9,0x90,0x2a,0x68,0x7d,0x66,
  0x56,0x47,0x50,0xe3,0x69,0x8f,0xd5,0x7c,0xd3,0x1a,0x5d,0xc8,0x39,0x0c,0x5b,0xee};
/* plaintext */
static const int8u plaintext[MBX_RSA4K_DATA_BYTE_LEN] = {
  0x42,0x4d,0xbf,0x13,0xf4,0x9f,0xa6,0x91,0x16,0x82,0xa6,0x65,0x4d,0xfd,0x7b,0x4d,
  0x5e,0xde,0x1e,0x58,0xa2,0x20,0x2a,0x4b,0xbb,0xb6,0xd3,0xe5,0x7c,0x4b,0x0c,0x00,
  0xa7,0x7a,0x57,0xf5,0xfb,0x6c,0x99,0x77,0xb1,0xd5,0xa3,0x3f,0x5e,0x86,0xad,0xff,
  0x29,0xdf,0x9a,0x19,0xcf,0xf6,0xd9,0x33,0xf7,0x83,0x79,0x3f,0xd3,0x50,0x70,0x91,
  0xc5,0x98,0xb5,0x10,0x2a,0x6d,0x91,0x3d,0x86,0x24,0x9a,0x07,0x9a,0x4c,0x5e,0x34,
  0xb4,0x4e,0x47,0x63,0xf8,0xb6,0x22,0x53,0xee,0x1a,0xbb,0x97,0x63,0xa3,0x52,0x5b,
  0x8d,0x87,0xbb,0x30,0x28,0xa1,0xc4,0x83,0x62,0x34,0x57,0xb2,0x88,0x0e,0xc9,0x5e,
  0xa4,0x23,0x0d,0x37,0x86,0x1e,0x69,0x2b,0x27,0xbc,0xe2,0x73,0x10,0x20,0x03,0x3a,
  0x3d,0xfe,0x35,0x9a,0xf4,0x9f,0x4b,0xa1,0x01,0x4c,0x4c,0x72,0xf7,0x83,0x06,0xf5,
  0x27,0x10,0xda,0xf5,0x13,0x4e,0xd2,0x61,0x95,0x94,0x67,0x7d,0x34,0x96,0x43,0x94,
  0x98,0x48,0xa3,0xb8,0x5c,0xa8,0xb7,0x55,0x02,0x35,0xc5,0x72,0x52,0xc7,0xf8,0xb4,
  0x4d,0xba,0xe4,0xe0,0x41,0xf6,0xec,0x6b,0xae,0xdc,0x09,0xdb,0x27,0x63,0x85,0xba,
  0xec,0xf9,0xc6,0x2c,0xbe,0xcd,0x67,0x10,0xb4,0x10,0x8a,0xba,0x9c,0xae,0x3e,0x01,
  0x3a,0x44,0x1a,0x64,0x63,0xd0,0xe5,0x4b,0x1c,0xdb,0x0b,0xdf,0xf9,0xad,0xba,0x7b,
  0x57,0xbe,0x68,0x70,0x97,0x82,0xe1,0x67,0x71,0xce,0x29,0x29,0x8c,0xde,0x3c,0xb8,
  0x45,0x54,0x7b,0x00,0x0b,0x93,0xf1,0x33,0x66,0x23,0x63,0xbb,0x52,0xcf,0x0d,0xe7,
  0x3f,0xbf,0x67,0xef,0x4d,0x54,0x8c,0x97,0x83,0x03,0xe0,0xec,0x9c,0xfd,0x0b,0x4e,
  0xae,0x37,0xa7,0xe2,0x52,0x44,0x21,0x97,0x3c,0xf4,0x13,0xed,0x39,0xa4,0x2f,0x40,
  0x48,0x3e,0x9e,0x15,0xee,0xb6,0x34,0x65,0xc9,0xf0,0xf9,0x7a,0x83,0x29,0x94,0x14,
  0xc7,0xe4,0x8e,0x5a,0xbd,0x24,0x11,0xb1,0x59,0xb4,0xd4,0x7e,0xf0,0xc4,0x11,0x16,
  0x59,0xb1,0x96,0xcf,0x88,0x72,0x25,0xdc,0x37,0x0a,0x0b,0x0c,0xa0,0xe7,0xc7,0x8a,
  0x58,0x29,0x19,0xdb,0xe8,0xba,0x80,0x86,0x80,0x7d,0xc5,0x4f,0x8e,0x65,0x10,0xc2,
  0x4b,0x19,0xc5,0x54,0xdf,0x1d,0x17,0x45,0x9f,0x48,0xb0,0xeb,0xf8,0x46,0xee,0x10,
  0x26,0xc1,0x3e,0xd6,0x6f,0x1c,0x55,0x76,0x9e,0x3d,0x6a,0xfb,0xee,0xa5,0x2f,0x83,
  0x7f,0xa7,0x83,0xee,0xb0,0x35,0x16,0xa6,0x8b,0x6b,0x48,0xa7,0x74,0x9f,0x04,0x16,
  0x9c,0xf0,0xb2,0x26,0x1a,0xb9,0x42,0x7e,0x57,0x14,0x8a,0xae,0x07,0xa3,0x61,0xc4,
  0x07,0xae,0xd5,0x02,0x7a,0xcd,0x51,0x4b,0xa6,0xd2,0x66,0x98,0x68,0x75,0xc4,0x91,
  0xcc,0x1a,0x70,0x45,0x1a,0x24,0x76,0x85,0x9d,0x18,0xea,0x22,0xd3,0xa7,0x2b,0x5f,
  0x1e,0xae,0x59,0x40,0xc9,0x18,0x01,0x84,0xe2,0xbc,0xf0,0x7b,0x69,0xd2,0x6e,0xfd,
  0xf9,0xc6,0x28,0x0f,0x2d,0x0a,0x65,0x04,0x0b,0xc4,0x1e,0x96,0x2a,0x23,0x4e,0xdc,
  0xd4,0x4e,0x01,0x9d,0x70,0xcf,0x7e,0x01,0x8a,0x11,0x96,0x2e,0x46,0x0b,0xa5,0x72,
  0x74,0xf0,0x73,0x4d,0x76,0x2a,0x67,0x40,0xa7,0xfe,0xe8,0x68,0x28,0x7c,0xa0,0x41};
/* ciphertext */
static const int8u ciphertext[MBX_RSA4K_DATA_BYTE_LEN] = {
  0x61,0x05,0xb5,0xe6,0x95,0xd0,0xc7,0x8e,0x32,0x0a,0x42,0xe5,0xd5,0x26,0x49,0xaa,
  0xd4,0x22,0x5b,0x43,0x1d,0x37,0x6d,0xcf,0xac,0x38,0x33,0x61,0xd7,0x84,0xe5,0x33,
  0xb7,0x51,0x67,0xce,0x17,0xb3,0x96,0x0a,0x41,0xca,0x6c,0x38,0x16,0xd7,0xf9,0xe5,
  0x29,0xd7,0x42,0x40,0x06,0xdc,0x88,0x84,0x9f,0xff,0x6c,0x6d,0xb2,0x81,0xdc,0xe9,
  0x32,0xf0,0xa4,0xf9,0x04,0xe7,0xa3,0x2c,0x18,0x4f,0x72,0x8f,0xd4,0x1e,0x22,0x25,
  0xc8,0xee,0xb9,0xd0,0x22,0xeb,0x60,0x84,0x09,0xfe,0xca,0xdb,0x09,0xbe,0x9e,0xf6,
  0x46,0xfb,0x67,0x0a,0x4f,0xe1,0xb9,0xec,0xac,0xdb,0xcf,0x72,0x4d,0xe9,0xd3,0x0d,
  0x2d,0xe7,0x5a,0x8f,0xa6,0xc3,0x44,0x41,0x38,0x2a,0x0d,0x42,0xa7,0x81,0x98,0xf8,
  0x4e,0x3b,0x57,0x0e,0xa7,0xfd,0xf4,0xbd,0xed,0xde,0x44,0x77,0x0d,0x67,0xc6,0xbf,
  0x1e,0x94,0x0f,0x55,0xa5,0xb5,0xc8,0x0b,0x09,0x35,0xc5,0xec,0x17,0x8b,0x6d,0x85,
  0x45,0x88,0x58,0x85,0x90,0xf2,0xcf,0xff,0x55,0x58,0x18,0x50,0x98,0x50,0xfd,0xf1,
  0x5c,0xa3,0x6a,0x91,0xf1,0x13,0xd2,0x9d,0xee,0x85,0xd8,0x4d,0xf2,0xa8,0x63,0x4e,
  0x51,0x66,0xa3,0xbd,0x71,0xce,0x0c,0x46,0x66,0xfd,0xb1,0x50,0x19,0x53,0x13,0x7c,
  0x74,0x65,0x14,0x9c,0xbc,0x49,0x08,0x85,0x75,0x73,0x60,0x23,0x37,0xa5,0x9f,0xe8,
  0xd7,0xfa,0x73,0x0d,0x3c,0x99,0xcb,0xfc,0x22,0x0e,0x1f,0xb9,0xa6,0xc5,0xa3,0x21,
  0x00,0xed,0x33,0xbf,0x1f,0xfa,0x0a,0xe7,0x45,0x0a,0x40,0x90,0x68,0xd6,0x6e,0xbf,
  0x12,0xfc,0x23,0x89,0xa8,0xba,0x1c,0x32,0x45,0x41,0x11,0xae,0x4e,0xa2,0x1e,0xeb,
  0x12,0xf5,0x08,0x6a,0x6e,0x68,0x71,0x13,0x59,0xbd,0xc4,0xe2,0x1c,0xef,0x4a,0xf0,
  0x20,0xc4,0x8d,0x31,0x90,0xea,0x40,0xfc,0xbc,0x6b,0x5f,0xee,0x76,0x82,0x60,0x0a,
  0x42,0xb9,0xb2,0x10,0x45,0xba,0x0d,0x99,0x7f,0x62,0x82,0x1e,0xd3,0x70,0x6d,0xb5,
  0x22,0x7b,0x62,0x1e,0xc8,0x9c,0x2f,0xf8,0xbf,0x54,0x31,0x54,0xf8,0x1b,0xfe,0xc6,
  0x2e,0x9f,0x60,0xf7,0x02,0xd5,0x3d,0x45,0x2f,0x46,0x73,0x12,0x49,0xa6,0xeb,0x2c,
  0x29,0x82,0x05,0x96,0x7f,0xc9,0xeb,0xa4,0x4e,0x15,0x43,0x25,0xbf,0xcd,0x95,0xe0,
  0x1b,0x27,0x7f,0x13,0xcf,0xd3,0xea,0xab,0x68,0x19,0x51,0x6f,0xeb,0xf1,0xfc,0x83,
  0x2f,0x83,0x3f,0xbc,0x86,0xa6,0xec,0xa8,0x55,0x7f,0xd8,0x67,0xd3,0x50,0x06,0xf2,
  0xe6,0x4a,0x89,0xfe,0x00,0x21,0x81,0x92,0xfd,0xd7,0x04,0x98,0xef,0xe4,0x89,0xf2,
  0x48,0x90,0xa5,0xe3,0xd7,0x2e,0x29,0x12,0x78,0x85,0x53,0x58,0x03,0x60,0x1a,0x1b,
  0xc2,0x46,0x44,0xc1,0xe7,0x8b,0x42,0x6a,0x90,0x4b,0x0c,0x5e,0x78,0x4f,0x7f,0x15,
  0xda,0x58,0xd5,0x26,0xb6,0x7e,0xd2,0x5c,0xb0,0xd1,0x43,0x1f,0xf5,0x26,0xde,0x89,
  0x07,0x48,0x31,0xc3,0x0c,0x73,0xd9,0xdb,0x6b,0x3f,0xf0,0x9c,0x05,0x7e,0x9b,0x07,
  0xac,0xbb,0x6a,0xe7,0x99,0xd6,0x95,0xec,0xcc,0xe5,0x25,0x4a,0x35,0x50,0xb6,0xc6,
  0x69,0xd8,0x43,0x59,0x3f,0x0c,0xde,0xf7,0xea,0x9c,0xe6,0xb8,0xf5,0x10,0x69,0xd8};

DLL_PUBLIC
fips_test_status fips_selftest_mbx_rsa4k_public_mb8(void) {
  fips_test_status test_result = MBX_ALGO_SELFTEST_OK;

  /* output ciphertext */
  int8u out_ciphertext[MBX_LANES][MBX_RSA4K_DATA_BYTE_LEN];
  /* key operation */
  const mbx_RSA_Method* method = mbx_RSA4K_pub65537_Method();

  /* function input parameters */
  // plaintext
  const int8u *pa_plaintext[MBX_LANES] = {
    plaintext, plaintext, plaintext, plaintext,
    plaintext, plaintext, plaintext, plaintext};
  // ciphertext
  int8u *pa_ciphertext[MBX_LANES] = {
    out_ciphertext[0], out_ciphertext[1], out_ciphertext[2], out_ciphertext[3],
    out_ciphertext[4], out_ciphertext[5], out_ciphertext[6], out_ciphertext[7]};
  // moduli
  const int64u *pa_moduli[MBX_LANES] = {
    (int64u *)moduli, (int64u *)moduli, (int64u *)moduli, (int64u *)moduli,
    (int64u *)moduli, (int64u *)moduli, (int64u *)moduli, (int64u *)moduli};

  /* test function */
  mbx_status expected_status_mb8 = MBX_SET_STS_ALL(MBX_STATUS_OK);

  mbx_status sts;
  sts = mbx_rsa_public_mb8(pa_plaintext, pa_ciphertext, pa_moduli, MBX_RSA4K_DATA_BIT_LEN, method, NULL);
  if (expected_status_mb8 != sts) {
    if (sts == MBX_SET_STS_ALL(MBX_STATUS_UNSUPPORTED_ISA_ERR)) {
      test_result = MBX_ALGO_SELFTEST_UNSUPPORTED_ISA_ERR;
    }
    else {
      test_result = MBX_ALGO_SELFTEST_KAT_ERR;
    }
  }
  // compare output ciphertext to known answer
  int output_status;
  for (int i = 0; (i < MBX_LANES) && (MBX_ALGO_SELFTEST_OK == test_result); ++i) {
    output_status = mbx_is_mem_eq(pa_ciphertext[i], MBX_RSA4K_DATA_BYTE_LEN, ciphertext, MBX_RSA4K_DATA_BYTE_LEN);
    if (!output_status) { // wrong output
      test_result = MBX_ALGO_SELFTEST_KAT_ERR;
    }
  }

  return test_result;
}

#ifndef BN_OPENSSL_DISABLE
/* exponent (for ssl function only) */
static const int8u exponent[MBX_RSA_PUB_EXP_BYTE_LEN] = {0x01,0x00,0x01};

// memory free macro
#define MEM_FREE(BN_PTR1, BN_PTR2) { \
  BN_free(BN_PTR1);                  \
  BN_free(BN_PTR2); }

DLL_PUBLIC
fips_test_status fips_selftest_mbx_rsa4k_public_ssl_mb8(void) {

  fips_test_status test_result = MBX_ALGO_SELFTEST_OK;

  /* output ciphertext */
  int8u out_ciphertext[MBX_LANES][MBX_RSA4K_DATA_BYTE_LEN];
  /* ssl exponent */
  BIGNUM* BN_e = BN_new();
  /* ssl moduli */
  BIGNUM* BN_moduli = BN_new();
  /* check if allocated memory is valid */
  if(NULL == BN_e || NULL == BN_moduli) {
    test_result = MBX_ALGO_SELFTEST_BAD_ARGS_ERR;
    MEM_FREE(BN_e, BN_moduli)
    return test_result;
  }

  /* function status and expected status */
  mbx_status sts;
  mbx_status expected_status_mb8 = MBX_SET_STS_ALL(MBX_STATUS_OK);
  /* output validity status */
  int output_status;

  /* set ssl parameters */
  BN_lebin2bn(exponent, MBX_RSA_PUB_EXP_BYTE_LEN, BN_e);
  BN_lebin2bn(moduli, MBX_RSA4K_DATA_BYTE_LEN, BN_moduli);

  /* function input parameters */
  // plaintext
  const int8u *pa_plaintext[MBX_LANES] = {
    plaintext, plaintext, plaintext, plaintext,
    plaintext, plaintext, plaintext, plaintext};
  // ciphertext
  int8u *pa_ciphertext[MBX_LANES] = {
    out_ciphertext[0], out_ciphertext[1], out_ciphertext[2], out_ciphertext[3],
    out_ciphertext[4], out_ciphertext[5], out_ciphertext[6], out_ciphertext[7]};
  // moduli
  const BIGNUM *pa_moduli[MBX_LANES] = {
    (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli,
    (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli, (const BIGNUM *)BN_moduli};
  const BIGNUM *pa_e[MBX_LANES] = {
    (const BIGNUM *)BN_e, (const BIGNUM *)BN_e, (const BIGNUM *)BN_e, (const BIGNUM *)BN_e,
    (const BIGNUM *)BN_e, (const BIGNUM *)BN_e, (const BIGNUM *)BN_e, (const BIGNUM *)BN_e};

  /* test function */
  sts = mbx_rsa_public_ssl_mb8(pa_plaintext, pa_ciphertext, pa_e, pa_moduli, MBX_RSA4K_DATA_BIT_LEN);
  if (expected_status_mb8 != sts) {
    if (sts == MBX_SET_STS_ALL(MBX_STATUS_UNSUPPORTED_ISA_ERR)) {
      test_result = MBX_ALGO_SELFTEST_UNSUPPORTED_ISA_ERR;
    }
    else {
      test_result = MBX_ALGO_SELFTEST_KAT_ERR;
    }
  }
  // compare output signature to known answer
  for (int i = 0; (i < MBX_LANES) && (MBX_ALGO_SELFTEST_OK == test_result); ++i) {
    output_status = mbx_is_mem_eq(pa_ciphertext[i], MBX_RSA4K_DATA_BYTE_LEN, ciphertext, MBX_RSA4K_DATA_BYTE_LEN);
    if (!output_status) { // wrong output
      test_result = MBX_ALGO_SELFTEST_KAT_ERR;
    }
  }

  // memory free
  MEM_FREE(BN_e, BN_moduli)

  return test_result;
}

#endif // BN_OPENSSL_DISABLE
#endif // MBX_FIPS_MODE
