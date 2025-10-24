program main
implicit none
integer :: i
integer :: ntally
character(256) :: numc, regc, volc, tallyc, tallyerrc
real*4, dimension(6) :: num,reg,vol,dose,doserr
real*4, dimension(6) :: dosed,doseu
character(256),dimension(6) :: organs
real*4 :: maxvaldose

organs=[character(256) :: "Llung", "Rlung", "heartTB","spineD","brain","headFS"]


open(11,file='maxy.tmp')

open(10,file='plotsumtally.tmp')



open(20,file='sumtallyres.tmp')

read(20,*) numc, regc, volc, tallyc, tallyerrc

do i=1,6
read(20,*) num(i),reg(i),vol(i),dose(i),doserr(i)
!print*, num(i),reg(i),vol(i),dose(i),doserr(i)
end do
close(20)


do i=1,6
dosed(i) = dose(i)-( dose(i)*doserr(i) )
doseu(i) = dose(i)+( dose(i)*doserr(i) )
write(10,*) i,dosed(i),dose(i),doseu(i)

end do

maxvaldose= maxval(doseu)

write(11,*) maxvaldose

close(11)






end program main
