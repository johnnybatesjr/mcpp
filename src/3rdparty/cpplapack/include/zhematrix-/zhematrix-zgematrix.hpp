//=============================================================================
/*! zhematrix+zgematrix operator */
inline _zgematrix operator+(const zhematrix& matA, const zgematrix& matB)
{VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.n || matA.n!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.n << "x" << matA.n << ") + (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  zgematrix newmat(matB);
  for(long i=0; i<matA.n; i++){ for(long j=0; j<matA.n; j++){
    newmat(i,j)+=matA(i,j);
  }}
  
  return _(newmat);
}

//=============================================================================
/*! zhematrix-zgematrix operator */
inline _zgematrix operator-(const zhematrix& matA, const zgematrix& matB)
{VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.n || matA.n!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a summation." << std::endl
              << "Your input was (" << matA.n << "x" << matA.n << ") + (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG
  
  zgematrix newmat(-matB);
  for(long i=0; i<matA.n; i++){ for(long j=0; j<matA.n; j++){
    newmat(i,j)+=matA(i,j);
  }}
  
  return _(newmat);
}


//=============================================================================
/*! zhematrix*zgematrix operator */
inline _zgematrix operator*(const zhematrix& matA, const zgematrix& matB)
{VERBOSE_REPORT;
#ifdef  CPPL_DEBUG
  if(matA.n!=matB.m){
    ERROR_REPORT;
    std::cerr << "These two matrises can not make a product." << std::endl
              << "Your input was (" << matA.n << "x" << matA.n << ") * (" << matB.m << "x" << matB.n << ")." << std::endl;
    exit(1);
  }
#endif//CPPL_DEBUG

  zgematrix newmat( matA.n, matB.n );
  zhemm_( 'l', 'l', matA.n, matB.n, comple(1.0,0.0), 
          matA.array, matA.n, matB.array, matB.m, 
          comple(0.0,0.0), newmat.array, newmat.m );
  
  return _(newmat);
}
