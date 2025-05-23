PROGRAM main
   USE sparse_mod
   IMPLICIT NONE

  TYPE(sparse_matrix) :: mat1
  TYPE(sparse_matrix) :: mat2
  TYPE(sparse_matrix) :: mat3
  TYPE(sparse_matrix) :: mat4



   CALL sparse_create(mat1,3,3,2)
   CALL sparse_create(mat2,3,3,4)
   CALL sparse_create(mat3,3,3,1)


    mat1%a = [5,-7]
    mat1%ia = [1,1,3,3]
    mat1%ja = [1,2]

    mat2%a = [3,-6,4,-3]
    mat2%ia = [1,2,3,5]
    mat2%ja = [2,2,1,3]


     mat3%a = [8]
     mat3%ja = [2]
     mat3%ia = [1,1,1,2]

     mat4 = mat1 + mat2 +  mat3

     CALL print_sparse(mat4)

     CALL sparse_destroy(mat1)
     CALL sparse_destroy(mat2)
     CALL sparse_destroy(mat3)
     CALL sparse_destroy(mat4)

end