/* SPDX-License-Identifier: BSD-2-Clause */
/*******************************************************************************
 * Copyright 2018-2019, Fraunhofer SIT sponsored by Infineon Technologies AG
 * All rights reserved.
 ******************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "tss2_fapi.h"
#include "tss2_esys.h"

#include "fapi_int.h"
#define LOGMODULE fapi
#include "util/log.h"
#include "util/aux_util.h"

/** One-Call function for Fapi_GetEsys
 *
 * Fapi_GetEsys returns the ESYS_CONTEXT currently used by the provided FAPI_CONTEXT.
 * The purpose is to enable advanced access to the TPM that is currently being talked to.
 *
 *
 * @param[in,out] context The FAPI_CONTEXT
 * @param[out] tcti The ESYS_CONTEXT used to talk to the current TPM.
 *
 * @retval TSS2_RC_SUCCESS: if the function call was a success.
 * @retval TSS2_FAPI_RC_BAD_REFERENCE: if context, tcti is NULL.
 * @retval TSS2_FAPI_RC_BAD_CONTEXT: if context corruption is detected.
 * @retval TSS2_FAPI_RC_NO_TPM: if FAPI was started in non-TPM mode.
 */
TSS2_RC
Fapi_GetEsys(
    FAPI_CONTEXT  *context,
    ESYS_CONTEXT  **esys_context)
{
    LOG_TRACE("called for context:%p", context);

    /* Check for NULL parameters */
    check_not_null(context);
    check_not_null(esys_context);

    /* Check if FAPI was started in a non-TPM mode. */
    if (!context->esys)
        return_error(TSS2_FAPI_RC_NO_TPM, "Fapi is running in non-TPM mode");

    /* Retrieve the ESYS. */
    *esys_context = context->esys;

    LOG_DEBUG("finished");
    return TSS2_RC_SUCCESS;
}
