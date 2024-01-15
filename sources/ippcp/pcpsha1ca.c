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
// 
//  Purpose:
//     Cryptography Primitive.
//     Digesting message according to SHA1
// 
//  Contents:
//    cpFinalizeSHA1()
// 
// 
*/

#include "owndefs.h"
#include "owncp.h"
#include "pcphash.h"
#include "pcphash_rmf.h"
#include "pcptool.h"
#include "pcpsha1stuff.h"


IPP_OWN_DEFN (void, cpFinalizeSHA1, (DigestSHA1 pHash, const Ipp8u* inpBuffer, int inpLen, Ipp64u processedMsgLen))
{
   /* select processing  function */
   #if (_SHA_NI_ENABLING_==_FEATURE_ON_)
   cpHashProc updateFunc = UpdateSHA1ni;
   #elif (_SHA_NI_ENABLING_==_FEATURE_TICKTOCK_)
   cpHashProc updateFunc = IsFeatureEnabled(ippCPUID_SHA)? UpdateSHA1ni : UpdateSHA1;
   #else
   cpHashProc updateFunc = UpdateSHA1;
   #endif

   /* local buffer and it length */
   Ipp8u buffer[MBS_SHA1*2];
   int bufferLen = inpLen < (MBS_SHA1-(int)MLR_SHA1)? MBS_SHA1 : MBS_SHA1*2; 

   /* copy rest of message into internal buffer */
   CopyBlock(inpBuffer, buffer, inpLen);

   /* pad message */
   buffer[inpLen++] = 0x80;
   PadBlock(0, buffer+inpLen, (cpSize)(bufferLen-inpLen-(int)MLR_SHA1));

   /* put processed message length in bits */
   processedMsgLen = ENDIANNESS64(processedMsgLen<<3);
   ((Ipp64u*)(buffer+bufferLen))[-1] = processedMsgLen;

   /* copmplete hash computation */
   updateFunc(pHash, buffer, bufferLen, sha1_cnt);
}
