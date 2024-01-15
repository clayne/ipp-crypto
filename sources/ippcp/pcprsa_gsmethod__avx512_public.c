/*************************************************************************
* Copyright (C) 2002 Intel Corporation
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

/*
// Montgomery engine preparation (GetSize/init/Set)
*/

/*
//     Intel(R) Integrated Performance Primitives. Cryptography Primitives.
// 
//     Context:
//        gsMethod_RSA_gpr_public()
//
*/

#include "owncp.h"
#include "pcpngmontexpstuff.h"
#include "gsscramble.h"
#include "pcpngrsamethod.h"
#include "pcpngrsa.h"

#if (_IPP32E>=_IPP32E_K1)
#include "pcpngmontexpstuff_avx512.h"

IPP_OWN_DEFN (gsMethod_RSA*, gsMethod_RSA_avx512_public, (void))
{
    static gsMethod_RSA m = {
        RSA_AVX512_MIN_BITSIZE, RSA_AVX512_MAX_BITSIZE, /* RSA range */

        /* public key exponentiation: public, binary, avx512 */
        gsMontExpBinBuffer_avx512,
        gsMontExpBin_BNU_avx512,
        NULL
    };
    return &m;
}
#endif /* _IPP32E_L9 */
