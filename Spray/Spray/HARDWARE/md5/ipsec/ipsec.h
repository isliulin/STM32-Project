/*
 * embedded IPsec	
 * Copyright (c) 2003 Niklaus Schild and Christian Scheurer, HTI Biel/Bienne
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 */

/** @file ipsec.h
 *  @brief Header of embedded IPsec implementation
 *
 *  @author Christian Scheurer <http://www.christianscheurer.ch> 
 *
 *
 * This document is part of <EM>embedded IPsec<BR>
 * Copyright (c) 2003 Niklaus Schild and Christian Scheurer, HTI Biel/Bienne<BR>
 * All rights reserved.</EM><HR>
 */


#ifndef __IPSEC_H__
#define __IPSEC_H__

#include "ipsec/types.h"
#include "netif/ipsecdev.h"

#include "ipsec/debug.h"

#include "ipsec/ipsec.h"
#include "ipsec/util.h"
#include "ipsec/sa.h"
#include "ipsec/ah.h"
#include "ipsec/esp.h"

#define IPSEC_DES_KEY_LEN		(8)							/**< Defines the size of a DES key in bytes */
#define IPSEC_3DES_KEY_LEN		(IPSEC_DES_KEY_LEN*3)		/**< Defines the length of a 3DES key in bytes */
#define IPSEC_MAX_ENCKEY_LEN	(32)						/**< 32*8 = 256, Defines the maximum encryption key length of our IPsec system */

#define IPSEC_AUTH_ICV			(12)						/**< Defines the authentication key length in bytes (12 bytes for 96bit keys) */
#define IPSEC_AUTH_MD5_KEY_LEN	(16)						/**< Length of MD5 secret key  */
#define IPSEC_AUTH_SHA1_KEY_LEN	(20)						/**< Length of SHA1 secret key */
#define IPSEC_MAX_AUTHKEY_LEN   (32)						/**< 64*8 = 512, Maximum length of authentication keys */

#define IPSEC_MIN_IPHDR_SIZE	(20) 	/**< Defines the minimum IP header size (in bytes).*/
#define IPSEC_SEQ_MAX_WINDOW	(32)	/**< Defines the maximum window for Sequence Number checks (used as anti-replay protection) */

#define IPSEC_IV_SIZE_MAX	(16)
#define IPSEC_IV_SIZE_AES	(16)

//int ipsec_input(unsigned char *, int, int *, int *, void *);
//int ipsec_output(unsigned char *, int , int *, int *, __u32, __u32, void *);
int ipsec_input(unsigned char *packet, int packet_size,  int *payload_offset, int *payload_size,  void *databasestmp);
int ipsec_output(unsigned char *packet, int packet_size, int *payload_offset, int *payload_size, __u32 src, __u32 dst, void *spdtmp);

#endif 
