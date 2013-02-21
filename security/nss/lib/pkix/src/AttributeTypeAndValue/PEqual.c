/* 
 * The contents of this file are subject to the Mozilla Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 * 
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 * 
 * The Original Code is the Netscape security libraries.
 * 
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are 
 * Copyright (C) 1994-2000 Netscape Communications Corporation.  All
 * Rights Reserved.
 * 
 * Contributor(s):
 * 
 * Alternatively, the contents of this file may be used under the
 * terms of the GNU General Public License Version 2 or later (the
 * "GPL"), in which case the provisions of the GPL are applicable 
 * instead of those above.  If you wish to allow use of your 
 * version of this file only under the terms of the GPL and not to
 * allow others to use your version of this file under the MPL,
 * indicate your decision by deleting the provisions above and
 * replace them with the notice and other provisions required by
 * the GPL.  If you do not delete the provisions above, a recipient
 * may use your version of this file under either the MPL or the
 * GPL.
 */

#ifdef DEBUG
static const char CVS_ID[] = "@(#) $Source$ $Revision$ $Date$ $Name$";
#endif /* DEBUG */

#ifndef PKIX_H
#include "pkix.h"
#endif /* PKIX_H */

/*
 * nssPKIXAttributeTypeAndValue_Equal
 *
 * 
 *
 * The error may be one of the following values:
 *  NSS_ERROR_INVALID_PKIX_ATAV
 *
 * Return value:
 *  PR_TRUE if the two objects have equal values
 *  PR_FALSE otherwise
 *  PR_FALSE upon error
 */

NSS_IMPLEMENT PRBool
nssPKIXAttributeTypeAndValue_Equal
(
  NSSPKIXAttributeTypeAndValue *atav1,
  NSSPKIXAttributeTypeAndValue *atav2,
  PRStatus *statusOpt
)
{
  NSSItem one, two;

#ifdef NSSDEBUG
  if( PR_SUCCESS != nssPKIXAttributeTypeAndValue_verifyPointer(atav1) ) {
    return PR_FAILURE;
  }

  if( PR_SUCCESS != nssPKIXAttributeTypeAndValue_verifyPointer(atav2) ) {
    return PR_FAILURE;
  }
#endif /* NSSDEBUG */

  if( (PRStatus *)NULL != statusOpt ) {
    *statusOpt = PR_SUCCESS;
  }

  one.size = atav1->asn1type.size;
  one.data = atav1->asn1type.data;
  two.size = atav2->asn1type.size;
  two.data = atav2->asn1type.data;

  if( PR_FALSE == nssItem_Equal(&one, &two, statusOpt) ) {
    return PR_FALSE;
  }

  one.size = atav1->asn1value.size;
  one.data = atav1->asn1value.data;
  two.size = atav2->asn1value.size;
  two.data = atav2->asn1value.data;

  return nssItem_Equal(&one, &two, statusOpt);
}