#pragma once

#include "params.h"
#include "polyvec.h"
#include <buffer.h>
#include <core.h>
#include <stdint.h>

void gen_matrix(polyvec * a, const uint8_t seed[KYBER_SYMBYTES], int transposed);

void indcpa_keypair(const BufferView & pubkey, const BufferView & seckey);

void indcpa_enc(
    uint8_t c[KYBER_INDCPA_BYTES], const uint8_t m[KYBER_INDCPA_MSGBYTES],
    const uint8_t pk[KYBER_INDCPA_PUBLICKEYBYTES], const uint8_t coins[KYBER_SYMBYTES]
);

void indcpa_dec(
    uint8_t m[KYBER_INDCPA_MSGBYTES], const uint8_t c[KYBER_INDCPA_BYTES], const uint8_t sk[KYBER_INDCPA_SECRETKEYBYTES]
);
