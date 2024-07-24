#pragma once

#include <pqc/ml-kem.h>

#include <buffer.h>
#include <core.h>


class MLKEMFactory : public AlgorithmFactory
{
public:
    virtual uint32_t cipher_id() const override;

    virtual std::unique_ptr<PQC_Context> create_context(const ConstBufferView & private_key) const override;

    virtual void generate_keypair(const BufferView & public_key, const BufferView & private_key) const override;
    virtual void kem_encode_secret(
        const BufferView & message, const ConstBufferView public_key, const BufferView & shared_secret
    ) const override;

    virtual size_t get_length(uint32_t type) const override;
};

class MLKEMContext : public KEMContext
{
public:
    MLKEMContext(const pqc_ml_kem_private_key * private_key)
    {
        private_key_.store(ConstBufferView::from_single(*private_key));
    }

    virtual void kem_decode_secret(ConstBufferView message, BufferView shared_secret) const override;

    virtual size_t get_length(uint32_t type) const override;

private:
    StackBuffer<PQC_ML_KEM_PRIVATE_KEYLEN> private_key_;
};
