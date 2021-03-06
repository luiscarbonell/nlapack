#include "routines.h"

void dporfs(const v8::FunctionCallbackInfo<v8::Value>& info) {
	char uplo = info[0]->Uint32Value();
 	lapack_int n = info[1]->Uint32Value();
	lapack_int nrhs = info[2]->Uint32Value();
	double *a = reinterpret_cast<double*>(GET_CONTENTS(info[3].As<v8::Float64Array>()));
	lapack_int lda = info[4]->Uint32Value();
	double *af = reinterpret_cast<double*>(GET_CONTENTS(info[5].As<v8::Float64Array>()));
	lapack_int ldaf = info[6]->Uint32Value();
	double *b = reinterpret_cast<double*>(GET_CONTENTS(info[7].As<v8::Float64Array>()));
	lapack_int ldb = info[8]->Uint32Value();
	double *x = reinterpret_cast<double*>(GET_CONTENTS(info[9].As<v8::Float64Array>()));
	lapack_int ldx = info[10]->Uint32Value();
	double *ferr = reinterpret_cast<double*>(GET_CONTENTS(info[11].As<v8::Float64Array>()));
	double *berr = reinterpret_cast<double*>(GET_CONTENTS(info[12].As<v8::Float64Array>()));

	lapack_int i = LAPACKE_dporfs(LAPACK_ROW_MAJOR, uplo, n, nrhs, a, lda, af, ldaf, b, ldb, x, ldx, ferr, berr);

	info.GetReturnValue().Set(
		v8::Number::New(info.GetIsolate(), i)
	);
}

void sporfs(const v8::FunctionCallbackInfo<v8::Value>& info) {
	char uplo = info[0]->Uint32Value();
 	lapack_int n = info[1]->Uint32Value();
	lapack_int nrhs = info[2]->Uint32Value();
	float *a = reinterpret_cast<float*>(GET_CONTENTS(info[3].As<v8::Float32Array>()));
	lapack_int lda = info[4]->Uint32Value();
	float *af = reinterpret_cast<float*>(GET_CONTENTS(info[5].As<v8::Float32Array>()));
	lapack_int ldaf = info[6]->Uint32Value();
	float *b = reinterpret_cast<float*>(GET_CONTENTS(info[7].As<v8::Float32Array>()));
	lapack_int ldb = info[8]->Uint32Value();
	float *x = reinterpret_cast<float*>(GET_CONTENTS(info[9].As<v8::Float32Array>()));
	lapack_int ldx = info[10]->Uint32Value();
	float *ferr = reinterpret_cast<float*>(GET_CONTENTS(info[11].As<v8::Float32Array>()));
	float *berr = reinterpret_cast<float*>(GET_CONTENTS(info[12].As<v8::Float32Array>()));

	lapack_int i = LAPACKE_sporfs(LAPACK_ROW_MAJOR, uplo, n, nrhs, a, lda, af, ldaf, b, ldb, x, ldx, ferr, berr);

	info.GetReturnValue().Set(
		v8::Number::New(info.GetIsolate(), i)
	);
}
