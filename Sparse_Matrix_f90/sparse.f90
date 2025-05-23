module sparse_mod

type sparse_matrix
integer(kind=4) :: nr, nc ! number of row and columns
integer(kind=4) :: nel    ! number of nonzeros elements

integer(kind=4),dimension(:),pointer :: ia ,ja
real(kind=8),dimension(:),pointer ::a
end type sparse_matrix 

interface operator(+)
       module procedure sparse_add  
end interface

contains 



subroutine sparse_create(mat,nr,nc,nel)
implicit none
type(sparse_matrix)::mat
integer(kind=4)::nr, nc, nel

mat%nr = nr
mat%nc = nc
mat%nel = nel

allocate(mat%ia(nr+1), mat%ja(nel), mat%a(nel))

end subroutine

subroutine sparse_destroy(mat)
implicit none
type(sparse_matrix):: mat

deallocate(mat%ia, mat%ja, mat%a)


end subroutine



        function sparse_add(mat1,mat2)result(mat)
        implicit none 
        type(sparse_matrix),intent(in)::mat1, mat2
        type(sparse_matrix)::mat
        integer(kind=4)::nonzeros         
        integer(kind=4)::ndegr(mat1%nr)         
        integer(kind=4),pointer::ic(:),jc(:)      
        real(kind=8),pointer::c(:)
        integer(kind=4),dimension(:),pointer :: ia, ja, ib, jb
        real(kind=8),dimension(:),pointer :: a, b 
        integer(kind=4)::ka,kb,kc, kamax, kbmax  
        integer(kind=4)::i,  j , j1, j2 
 
        call NonzeroElementApB(mat1,mat2,ndegr,nonzeros)
        !allocate(mat%ia(mat1%nr+1), mat%ja(nonzeros), mat%a(nonzeros))
        
        allocate(ic(mat1%nr+1), jc(nonzeros), c(nonzeros))
        ia => mat1%ia
        ja => mat1%ja
        a  => mat1%a

        ib => mat2%ia
        jb => mat2%ja 
        b  => mat2%a

        mat%ia => ic
        mat%ja => jc
        mat%a  => c

        mat%nr = mat1%nr
        mat%nc = mat1%nc
        mat%nel = sum(ndegr)

        ic(1) = 1 
        kc = 1

        do i = 1, mat%nr  
       
        ka = ia(i)
        kb = ib(i)
        kamax = ia(i+1) - 1
        kbmax = ib(i+1) - 1
        
        do j = 1 , ndegr(i)
        if(ka <= kamax) then
        j1 = ja(ka) 
        else
        j1 = mat1%nc + 1
        endif
        
        if(kb <= kbmax) then
        j2 = jb(kb)
        else
        j2 = mat1%nc + 1
        endif 

        if(j1 == j2 ) then
        c(kc) = a(ka) + b(kb) 
        jc(kc) = j1
        ka = ka + 1
        kb = kb + 1
        kc = kc + 1
        else if (j1 < j2) then
        
        jc(kc) = j1
        c(kc) = a(ka)
        ka = ka + 1
        kc = kc + 1
        
        elseif(j2 < j1) then
        jc(kc) = j2
        c(kc) = b(kb)
        kb = kb + 1
        kc = kc + 1
        endif

        enddo
        ic(i+1) = kc
        enddo 


        end function
        subroutine NonzeroElementApB(mat1,mat2,ndegr,nonzeros)
        implicit none
        type(sparse_matrix),intent(in)::mat1, mat2
        integer(kind=4)::ndegr(mat1%nr)
        logical::iw(mat1%nc)
        integer(kind=4)::nonzeros  
        integer(kind=4)::ii
        do ii = 1, mat1%nr 
        
        iw = .false.
        iw(mat1%ja(mat1%ia(ii):mat1%ia(ii+1)-1)) = .true. 
        iw(mat2%ja(mat2%ia(ii):mat2%ia(ii+1)-1)) = .true.
        ndegr(ii) =  count(iw)

        enddo
        nonzeros = sum(ndegr) 
        end subroutine


        subroutine print_sparse(mat)
        implicit none
        type(sparse_matrix):: mat

        write(*,*)"the row of sparse matrix is ", mat%nr
        write(*,*)"the column of sparse matrix is ", mat%nc
        write(*,*)"the nonzeros of sparse matrix is ", mat%nel

        write(*,*) "the value of sparse matrix is "
        write(*,*) mat%a

        write(*,*)"the ia of the sparse matrix is "
        write(*,*) mat%ia

        write(*,*)"the ja of the sparse matrix is"
        write(*,*) mat%ja 
        end subroutine 
        



end module







