/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CIRCULANT_H_RPCGEN
#define _CIRCULANT_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct myVector {
	int vectSize;
};
typedef struct myVector myVector;

#define CIRCULANT_PROG 0x23486756
#define DO_CIRC 1

#if defined(__STDC__) || defined(__cplusplus)
#define doCirculant 1
extern  int * docirculant_1(myVector *, CLIENT *);
extern  int * docirculant_1_svc(myVector *, struct svc_req *);
extern int circulant_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define doCirculant 1
extern  int * docirculant_1();
extern  int * docirculant_1_svc();
extern int circulant_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_myVector (XDR *, myVector*);

#else /* K&R C */
extern bool_t xdr_myVector ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CIRCULANT_H_RPCGEN */