/*
* Copyright (c) 2014-2016 IBM Corporation.
* All rights reserved.
*
* Copyright (c) 2017 MCCI Corporation
* All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*  * Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  * Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
*  * Neither the name of the <organization> nor the
*    names of its contributors may be used to endorse or promote products
*    derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef _lorabase_ph915_h_
#define _lorabase_ph915_h_

#ifndef _LMIC_CONFIG_PRECONDITIONS_H_
# include "lmic_config_preconditions.h"
#endif

/****************************************************************************\
|
| Basic definitions for PH915 (always in scope)
|
\****************************************************************************/

//
// Default frequency plan for PH 915MHz ISM band
// data rates
// this is a little confusing: the integer values of these constants are the
// DataRates from the LoRaWAN Regional Parmaeter spec. The names are just
// convenient indications, so we can use them in the rare case that we need to
// choose a DataRate by SF and configuration, not by DR code.

enum _dr_ph915_t {
        PH915_DR_SF12 = 0,
        PH915_DR_SF11,
        PH915_DR_SF10,
        PH915_DR_SF9,
        PH915_DR_SF8,
        PH915_DR_SF7,
        PH915_DR_SF7B,
        PH915_DR_FSK,
        PH915_DR_NONE
};

// Bands:
//  g1 :   1%  14dBm
//  g2 : 0.1%  14dBm
//  g3 :  10%  27dBm
//                 freq             band     datarates
enum {
        PH915_F1 = 916100000,      // g1   SF7-12
        PH915_F2 = 916300000,      // g1   SF7-12 FSK SF7/250
        PH915_F3 = 916500000,      // g1   SF7-12
        PH915_F4 = 915100000,      // g2   SF7-12
        PH915_F5 = 915300000,      // g2   SF7-12
        PH915_F6 = 915500000,      // g3   SF7-12
        PH915_J4 = 915700000,      // g2   SF7-12  used during join
        PH915_J5 = 915900000,      // g2   SF7-12   ditto
        PH915_J6 = 917900000,      // g2   SF7-12   ditto
};
enum {
        PH915_FREQ_MIN = 915000000,
        PH915_FREQ_MAX = 918000000
};
enum {
        PH915_TX_EIRP_MAX_DBM = 22      // 16 dBm EIRP. So subtract 3 dBm for a 3 dBi antenna.
};

enum { PH915_LMIC_REGION_EIRP = 1 };         // region uses EIRP

enum { DR_PAGE_PH915 = 0x10 * (LMIC_REGION_ph915 - 1) };

#endif /* _lorabase_ph915_h_ */