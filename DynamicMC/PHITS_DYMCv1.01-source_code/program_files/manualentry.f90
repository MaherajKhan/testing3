program manualentry
implicit none
logical :: there
character(len=8) :: fmt
character(256) :: name
character(256) :: x1
character(256) :: gg
character(256) :: wrkdir
character(256) :: wrkdiraux
character(256) :: namedir
character(256) :: namedirx
integer :: num
integer :: i
character(256) :: title
integer :: icntl
integer :: maxbch
integer :: maxcas
integer :: ih2o
real*4 :: emin
real*4 :: dmax
integer :: stype
real*4 :: dir
real*4 :: e0
character(256) :: proj
real*4 :: r0
real*4 :: z0
real*4 :: z1
character(400) :: enchar3
character(400) :: outfile
character(256), dimension(10) :: color !color matrix
real*4 :: height
real*4 :: meshsize
integer :: ndom
real*4 :: airad
integer, dimension(200) :: meshmatrixLin
integer, dimension(10,20) :: meshmatrix
integer :: j
integer :: k
integer :: ncount
integer :: jj
integer, dimension(:),allocatable :: meshdomr1
integer, dimension(:),allocatable :: meshdomc1
integer, dimension(:),allocatable :: meshdomr2
integer, dimension(:),allocatable :: meshdomc2
integer, dimension(:),allocatable :: meshdom
real*4 :: lwdmn1
real*4 :: lwdmn2
real*4 :: lwdmn3
real*4 :: lwdmn4
character(256), dimension(:), allocatable :: mat
integer :: material
real*4 :: density
character(len=20) str
integer :: itep
integer :: ntally
character(256), dimension(:),allocatable :: tally
real*4 :: x0
real*4 :: y0
integer :: nuclint
real*4 :: movx, movy
real*4 :: xsq1,ysq1,xsq1rl
real*4 :: xsq2,ysq2
real*4 :: xsq3,ysq3
real*4 :: xsq4,ysq4
real*4 :: xsq5,ysq5
real*4 :: xsq6,ysq6
real*4 :: xsq7,ysq7
real*4 :: xsq8,ysq8
real*4 :: xsq9,ysq9
real*4 :: xsq10,ysq10
real*4 :: xsq11,ysq11
real*4 :: xsq12,ysq12
real*4 :: xsq13,ysq13
real*4 :: px1,px2
real*4 :: py1,py2
real*4 :: sx1,sy1
real*4 :: czx1,czy1
real*4 :: px3,px4,py3,py4
real*4 :: rcx1,rcx10,rcx11,rcx12,rcx13,rcx14,rcx15,rcx16,rcx17,rcx18,rcx19
real*4 :: rcx2,rcx20,rcx21,rcx22,rcx23,rcx24,rcx25,rcx26
real*4 :: rcx3,rcx4,rcx5,rcx6,rcx7,rcx8,rcx9
real*4 :: rcy1,rcy10,rcy11,rcy12,rcy13,rcy14,rcy15,rcy16,rcy17,rcy18,rcy19
real*4 :: rcy2,rcy20,rcy21,rcy22,rcy23,rcy24,rcy25,rcy26
real*4 :: rcy3,rcy4,rcy5,rcy6,rcy7,rcy8,rcy9
real*4 :: sor
real*4 :: xsq14,xsq15,xsq16,xsq17,xsq18,xsq19,xsq20,xsq21,xsq22,xsq23,xsq24
real*4 :: ysq14,ysq15,ysq16,ysq17,ysq18,ysq19,ysq20,ysq21,ysq22,ysq23,ysq24
real*4 :: rho1,rho2,rho3,rho4,rho5,rho6,rho7,rho8,rho9,rho10,rho11,rho12,rho13,rho14,rho15,rho16
real*4 :: sx
real*4 :: sy
real*4 :: sz
real*4 :: px
real*4 :: py
real*4 :: step
integer :: coord
real*4 :: shx, shy,shl,shw,shz
integer :: shield
character*256, dimension(:), allocatable :: shieldmat,shieldfrac
real*4 :: shieldrho
integer :: nshield
character*256 :: dymcmode,RI,projectile
real*4 :: dtime, actlow
integer :: iterall
integer :: iterate
character(256) :: headerdummy
real*4,dimension(:),allocatable :: sxar,syar,szar,pxar,pyar


open(888,file='manlines.tmp')
read(888,*) iterall
close(888)

allocate(sxar(iterall))
allocate(syar(iterall))
allocate(szar(iterall))
allocate(pxar(iterall))
allocate(pyar(iterall))

open(999,file='manualinp.tmp')
read(999,*) headerdummy
do i=1,iterall
read(999,*) sxar(i),syar(i),szar(i),pxar(i),pyar(i)
end do


close(999)

do iterate=1,iterall


!user manual entry from
sx = sxar(iterate)
sy = syar(iterate)
sz = szar(iterate)
px = pxar(iterate)
py = pyar(iterate)
!end of user manual entry


open(122,file='dymcmode.tmpz')
read(122,*) dymcmode
close(122)

if(trim(dymcmode)=="RI")then
open(122,file='dtime.tmp')
read(122,*) dtime
close(122)

open(122,file='strength.tmp')
read(122,*) actlow
close(122)

open(122,file='RI.tmp')
read(122,*) RI
close(122)

open(122,file='projectile.tmp')
read(122,*) projectile
close(122)
end if





open(804,file='coord.tmp')
read(804,*) coord
close(804)


open(805,file='step.tmp')
read(805,*) step
close(805)





movx = px !4.0

movy = py !0.0

xsq1 = -2.0 + movx 
ysq1 = 1.0 + movy
xsq1rl = 2.0 + movx 


px1 = -2 + movx
px2 = 2 + movx

sx1 = -2.0 + movx
sy1 = 1.0 + movy

czx1 = 0.0 + movx
czy1 = -7.8 + movy




!open(556,file='shield.tmp')
!read(556,*) shield
!close(556)

shield = 0


x0= sx
y0 = sy
z0= sz

open(561,file='ntally.tmp')
read(561,*) ntally
close(561)

allocate(tally(ntally))

open(562,file='tally.tmp')
do i=1,ntally
read(562,*) tally(i)
!print*, tally(i)
end do
close(562)


open(777,file="working_dir.tmpz")
read(777,'(A)') wrkdir
close(777)

print*, trim(wrkdir) // '/'


wrkdiraux = trim(wrkdir) // '/'

name = '_code.inp'

namedir = '_folder'

fmt = '(I5.5)'

num=1

do i=1,1000

write(x1,fmt) num

namedirx = trim(x1) // trim(namedir)

!print*, trim(namedirx)

gg = trim(wrkdiraux) // trim(x1) // trim(name)

inquire(file=gg,exist=there)

if(there)then
num=num+1
end if

end do


write(x1,fmt) num



!name = num,'.stl'
gg = trim(wrkdiraux) // trim(x1) // trim(name)
!inquire(file=gg,exist=there)
!if(there)then
!num=num+1
!write(x1,fmt) num
!gg = trim(x1) // trim(name)
open(10,file=gg)


!open(10,file='code.inp')
open(333,file='runphits.bat',position='append')

!write(333,'(A)') '#!/bin/sh'

write(333,'(A,X,A)') 'phits.sh', trim(gg) 

write(333,'(A,X,A)') 'mkdir', trim(wrkdiraux) // trim(x1) 

write(333,'(A,X,A)') 'mv *.out *.eps', trim(wrkdiraux) // trim(x1)

write(333,'(A,X,A)') 'echo ', trim(x1) // trim(name) // ' run done!'
!print*, "enter title of code: "
!read*, title

close(333)

open(553,file='sumtally.tmp',position='append')
do i=1,ntally
write(553,'(A,X,A)') trim(wrkdiraux) // trim(x1) // "/organ_deposit_" // trim(tally(i)) // trim(".out")
end do
close(553)


title='generated by PHITS DynamicMC'

!parameters
icntl = 0
open(52,file='maxcas.tmp')
read(52,*) maxcas != 10000
close(52)

open(53,file='maxbch.tmp')
read(53,*) maxbch != 10
close(53)

 
ih2o = 69

emin = 0.5
dmax = 0.6




!source
!totfact =   1.0   
stype = 9 !sphereical   !3 !gaussian x,y,z indepdenent
if(trim(dymcmode)=="P")then
open(338,file='part.tmp')
read(338,*) proj
!proj = 'proton'
close(338)
end if

dir = 1.0

!open(54,file='srad.tmp')
!read(54,*) r0 !mm input
!close(54)

r0 = 0.0 !r0*0.1

!open(542,file='dist.tmp')
!read(542,*) z0
!z1 = z0  !plane source
!z0 = -25.0
!z1 = -25.0
!z0 = z0*(-1.00)
!z1 = z1*(-1.00)
!close(542)
if(trim(dymcmode)=="P")then
open(55,file='en.tmp')
read(55,*) e0 != 80.0
close(55)
end if

!************************************
!************************************
!write(enchar3,'(I4,A,A)') int(e0),'MeV','_phits.out'

outfile= 'phits.out'  !trim(enchar3)

!print*, outfile

write(10,1) adjustl(trim("[ T i t l e ]"))
1 format(A)

write(10,*) trim(title) !adjustl(trim(title))
!2 format(A)

write(10,*) " "

write(10,3) adjustl(trim("[ P a r a m e t e r s ]"))
3 format(A)

write(10,4) "icntl   =",icntl
4 format(2X,A,4X,I2)
  
write(10,5) "maxcas   =",maxcas
5 format(X,A,4X,I10)

write(10,6) "maxbch   =",maxbch
6 format(X,A,4X,I10)

write(10,1) "ireschk  =      1     # (D=0) Restart, 0:Check consistency, 1:No check"

write(10,7) "ih2o   =",ih2o
7 format(5X,A,4X,I4)


write(10,8) "file(6)  = ",trim(outfile)
8 format(X,A,X,A)

write(10,*) " "

!needs to be changed into an isotropic point source************
write(10,11) adjustl(trim("[ S o u r c e ]"))
11 format(A)

write(10,12) "s-type   =",stype
12 format(3X,A,X,I2)

if(trim(dymcmode)=="P")then
write(10,13) "proj   =",trim(proj)
13 format(4X,A,X,A)
elseif(trim(dymcmode)=="RI")then
write(10,13) "proj   =",trim(projectile)
end if

write(10,11) "dir   =   all"
!14 format(5X,A,2X,F5.2)

write(10,11) "r1   =  1.0E-10"
write(10,11) "r2   =  1.0E-10"
!write(10,15) "r1   =",r0
!write(10,15) "r2   =",r0
15 format(6X,A,2X,F8.3)

write(10,15) "x0   =",x0

write(10,15) "y0   =",y0

write(10,16) "z0   =",z0
16 format(6X,A,2X,F7.2)

!write(10,17) "z1   =",z1
!17 format(6X,A,2X,F7.2)
if(trim(dymcmode)=="P")then
write(10,18) "e0   =",e0
18 format(6X,A,2X,F8.3)
elseif(trim(dymcmode)=="RI")then
write(10,11) "e-type   =   28"
write(10,11) "ni   =  1"
write(10,798) adjustl(trim(RI)), actlow
798 format(8X,A,X,F8.3)
write(10,15) "dtime   =",dtime
write(10,11) "actlow   =  1.0e-10"

end if

!needs to be changed into an isotropic point source************

write(10,*) " "

write(10,19) adjustl(trim("[ M a t e r i a l ]"))
19 format(A)

write(10,19) adjustl(trim("mat[1]        $TISSUE-SOFT(ICRU-44)"))
write(10,19) adjustl(trim(" 1000 -10.5"))
write(10,19) adjustl(trim(" 6000 -25.6"))
write(10,19) adjustl(trim(" 7000 -2.7"))
write(10,19) adjustl(trim(" 8000 -60.2"))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 15000 -0.2"))
write(10,19) adjustl(trim(" 16000 -0.3"))
write(10,19) adjustl(trim(" 17000 -0.2"))
write(10,19) adjustl(trim(" 19000 -0.2"))

write(10,*) " "


write(10,19) adjustl(trim("mat[2]        $Heart-tissue(healthy)"))
write(10,19) adjustl(trim(" 1000 -10.4"))
write(10,19) adjustl(trim(" 6000 -13.9"))
write(10,19) adjustl(trim(" 7000 -2.90"))
write(10,19) adjustl(trim(" 8000 -71.8"))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 15000 -0.2"))
write(10,19) adjustl(trim(" 16000 -0.2"))
write(10,19) adjustl(trim(" 17000 -0.2"))
write(10,19) adjustl(trim(" 19000 -0.3"))

write(10,*) " "

write(10,19) adjustl(trim("mat[3]        $Blood(whole)"))
write(10,19) adjustl(trim(" 1000 -10.2"))
write(10,19) adjustl(trim(" 6000 -11.0"))
write(10,19) adjustl(trim(" 7000 -3.3"))
write(10,19) adjustl(trim(" 8000 -74.5"))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 15000 -0.1"))
write(10,19) adjustl(trim(" 16000 -0.2"))
write(10,19) adjustl(trim(" 17000 -0.3"))
write(10,19) adjustl(trim(" 19000 -0.2"))
write(10,19) adjustl(trim(" 26000 -0.1"))

write(10,*) " "

write(10,19) adjustl(trim("mat[4]        $Lung(healthy-inflated)"))
write(10,19) adjustl(trim(" 1000 -10.3"))
write(10,19) adjustl(trim(" 6000 -10.5"))
write(10,19) adjustl(trim(" 7000 -3.1"))
write(10,19) adjustl(trim(" 8000 -74.9"))
write(10,19) adjustl(trim(" 11000 -0.2"))
write(10,19) adjustl(trim(" 15000 -0.2"))
write(10,19) adjustl(trim(" 16000 -0.3"))
write(10,19) adjustl(trim(" 17000 -0.3"))
write(10,19) adjustl(trim(" 19000 -0.2"))
write(10,*) " "

write(10,19) adjustl(trim("mat[5]        $Brain(whole)"))
write(10,19) adjustl(trim(" 1000 -10.7"))
write(10,19) adjustl(trim(" 6000 -14.5"))
write(10,19) adjustl(trim(" 7000 -2.2"))
write(10,19) adjustl(trim(" 8000 -71.2"))
write(10,19) adjustl(trim(" 11000 -0.2"))
write(10,19) adjustl(trim(" 15000 -0.4"))
write(10,19) adjustl(trim(" 16000 -0.2"))
write(10,19) adjustl(trim(" 17000 -0.3"))
write(10,19) adjustl(trim(" 19000 -0.3"))
write(10,*) " "

write(10,19) adjustl(trim("mat[6]        $Skin"))
write(10,19) adjustl(trim(" 1000 -10.0"))
write(10,19) adjustl(trim(" 6000 -20.4"))
write(10,19) adjustl(trim(" 8000 -64.5"))
write(10,19) adjustl(trim(" 11000 -0.2"))
write(10,19) adjustl(trim(" 15000 -0.1"))
write(10,19) adjustl(trim(" 16000 -0.2"))
write(10,19) adjustl(trim(" 17000 -0.3"))
write(10,19) adjustl(trim(" 19000 -0.1"))
write(10,*) " "

write(10,19) adjustl(trim("mat[7]        $Skull(ICRU)"))
write(10,19) adjustl(trim(" 1000 -5.0"))
write(10,19) adjustl(trim(" 6000 -21.2"))
write(10,19) adjustl(trim(" 7000 -4.0"))
write(10,19) adjustl(trim(" 8000 -43.5"))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 12000 -0.2"))
write(10,19) adjustl(trim(" 15000 -8.1"))
write(10,19) adjustl(trim(" 16000 -0.3"))
write(10,19) adjustl(trim(" 20000 -17.6"))
write(10,*) " "

write(10,19) adjustl(trim("mat[8]        $Leg-bone"))
write(10,19) adjustl(trim(" 1000 -7.0"))
write(10,19) adjustl(trim(" 6000 -34.5"))
write(10,19) adjustl(trim(" 7000 -2.8"))
write(10,19) adjustl(trim(" 8000 -36.8 "))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 12000 -0.1"))
write(10,19) adjustl(trim(" 15000 -5.5"))
write(10,19) adjustl(trim(" 16000 -0.2"))
write(10,19) adjustl(trim(" 17000 -0.1"))
write(10,19) adjustl(trim(" 20000 -12.9"))

write(10,*) " "
write(10,19) adjustl(trim("mat[9]        $Arm-bone"))
write(10,19) adjustl(trim(" 1000 -6.0"))
write(10,19) adjustl(trim(" 6000 -31.4"))
write(10,19) adjustl(trim(" 7000 -3.1"))
write(10,19) adjustl(trim(" 8000 -36.9"))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 12000 -0.1"))
write(10,19) adjustl(trim(" 15000 -7.0"))
write(10,19) adjustl(trim(" 16000 -0.2"))
write(10,19) adjustl(trim(" 20000 -15.2"))

write(10,*) " "
write(10,19) adjustl(trim("mat[10]        $Facial-bone"))
write(10,19) adjustl(trim(" 1000 -4.6"))
write(10,19) adjustl(trim(" 6000 -19.9"))
write(10,19) adjustl(trim(" 7000 -4.1"))
write(10,19) adjustl(trim(" 8000 -43.5"))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 12000 -0.2"))
write(10,19) adjustl(trim(" 15000 -8.6"))
write(10,19) adjustl(trim(" 16000 -0.3"))
write(10,19) adjustl(trim(" 20000 -18.7"))

write(10,*) " "
write(10,19) adjustl(trim("mat[11]        $Ribs(1-9)"))
write(10,19) adjustl(trim(" 1000 -6.4"))
write(10,19) adjustl(trim(" 6000 -26.3"))
write(10,19) adjustl(trim(" 7000 -3.9"))
write(10,19) adjustl(trim(" 8000 -43.6"))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 12000 -0.1"))
write(10,19) adjustl(trim(" 15000 -6.0"))
write(10,19) adjustl(trim(" 16000 -0.3"))
write(10,19) adjustl(trim(" 17000 -0.1"))
write(10,19) adjustl(trim(" 19000 -0.1"))
write(10,19) adjustl(trim(" 20000 -13.1"))
write(10,*) " "

write(10,19) adjustl(trim("mat[12]        $Ribs(10-12)"))
write(10,19) adjustl(trim(" 1000 -5.6"))
write(10,19) adjustl(trim(" 6000 -23.5"))
write(10,19) adjustl(trim(" 7000 -4.0 "))
write(10,19) adjustl(trim(" 8000 -43.4"))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 12000 -0.1"))
write(10,19) adjustl(trim(" 15000 -7.2"))
write(10,19) adjustl(trim(" 16000 -0.3"))
write(10,19) adjustl(trim(" 17000 -0.1"))
write(10,19) adjustl(trim(" 19000 -0.1"))
write(10,19) adjustl(trim(" 20000 -15.6"))

write(10,*) " "
write(10,19) adjustl(trim("mat[13]        $Cervical-vertebrae"))
write(10,19) adjustl(trim(" 1000 -6.3"))
write(10,19) adjustl(trim(" 6000 -26.1"))
write(10,19) adjustl(trim(" 7000 -3.9"))
write(10,19) adjustl(trim(" 8000 -43.6"))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 12000 -0.1"))
write(10,19) adjustl(trim(" 15000 -6.1"))
write(10,19) adjustl(trim(" 16000 -0.3"))
write(10,19) adjustl(trim(" 17000 -0.1"))
write(10,19) adjustl(trim(" 19000 -0.1"))
write(10,19) adjustl(trim(" 20000 -13.3"))

write(10,*) " "
write(10,19) adjustl(trim("mat[14]        $Thoracic/Lumbal-vertebrae"))
write(10,19) adjustl(trim(" 1000 -7.0"))
write(10,19) adjustl(trim(" 6000 -28.7"))
write(10,19) adjustl(trim(" 7000 -3.8"))
write(10,19) adjustl(trim(" 8000 -43.7"))
write(10,19) adjustl(trim(" 12000 -0.1"))
write(10,19) adjustl(trim(" 15000 -5.1"))
write(10,19) adjustl(trim(" 16000 -0.2"))
write(10,19) adjustl(trim(" 17000 -0.1"))
write(10,19) adjustl(trim(" 19000 -0.1"))
write(10,19) adjustl(trim(" 20000 -11.1"))

write(10,*) " "
write(10,19) adjustl(trim("mat[15]        $Intervertebral-disks"))
write(10,19) adjustl(trim(" 1000 -9.6"))
write(10,19) adjustl(trim(" 6000 -9.9"))
write(10,19) adjustl(trim(" 7000 -2.2"))
write(10,19) adjustl(trim(" 8000 -74.4"))
write(10,19) adjustl(trim(" 11000 -0.5"))
write(10,19) adjustl(trim(" 15000 -2.2"))
write(10,19) adjustl(trim(" 16000 -0.9"))
write(10,19) adjustl(trim(" 17000 -0.3"))
write(10,*) " "

write(10,19) adjustl(trim("mat[16]        $AIR-DRY"))
write(10,19) adjustl(trim(" 6000 -0.000124"))
write(10,19) adjustl(trim(" 7000 -0.755267"))
write(10,19) adjustl(trim(" 8000 -0.231781"))
write(10,19) adjustl(trim(" 18000 -0.012827"))
write(10,*) " "

write(10,19) adjustl(trim("mat[17]        $TISSUE-SOFT-Tumor"))
write(10,19) adjustl(trim(" 1000 -10.5"))
write(10,19) adjustl(trim(" 6000 -25.6"))
write(10,19) adjustl(trim(" 7000 -2.7"))
write(10,19) adjustl(trim(" 8000 -60.2"))
write(10,19) adjustl(trim(" 11000 -0.1"))
write(10,19) adjustl(trim(" 15000 -0.2"))
write(10,19) adjustl(trim(" 16000 -0.3"))
write(10,19) adjustl(trim(" 17000 -0.2"))
write(10,19) adjustl(trim(" 19000 -0.2"))



write(10,*) " "


write(10,21) adjustl(trim("[ S u r f a c e ]"))
21 format(A)

write(10,22) "$Left-Lung"
22 format(A)

write(10,23) "100 sq 0.00444444 0.02040816 0.001720426 0 0 0 -1",xsq1,ysq1,"21.79084544"
23 format(A,X,F12.4,X,F12.4,X,A)

write(10,24) "101 px",px1
24 format(A,X,F12.4)

write(10,123) "102 pz 21.79084544"
123 format(A)


write(10,22) "$Right-Lung"

write(10,23) "110 sq 0.00444444 0.02040816 0.001784477 0 0 0 -1",xsq1rl,ysq1,"22.22747566"

write(10,24) "111 px",px2

write(10,23) "112 pz 22.22747566"

write(10,22) "$Sphere-out-heart"

write(10,26) "200 s",sx1,sy1,"31.5 5.8"
26 format(A,X,F12.4,X,F12.4,X,A)

write(10,22) "$Heart"

write(10,26) "210 s",sx1,sy1,"31.5 5.748"

write(10,26) "211 s",sx1,sy1,"31.5 4.861"


write(10,22) "$Spine"

write(10,26) "300 c/z",czx1,czy1,"2"

write(10,22) "301 pz 0"

write(10,22) "302 pz 0.4"

write(10,22) "303 pz 2.7 $1"

write(10,22) "304 pz 3.1"

write(10,22) "305 pz 5.4 $2"

write(10,22) "306 pz 5.8"

write(10,22) "307 pz 8.1 $3"

write(10,22) "308 pz 8.5"

write(10,22) "309 pz 10.8 $4"

write(10,22) "310 pz 11.2"

write(10,22) "311 pz 13.5 $5"

write(10,22) "312 pz 13.9"

write(10,22) "313 pz 16.2 $6"

write(10,22) "314 pz 16.6"

write(10,22) "315 pz 18.9 $7"

write(10,22) "316 pz 19.3"

write(10,22) "317 pz 21.6 $8"

write(10,22) "318 pz 22.0"

write(10,22) "319 pz 24.3 $9"

write(10,22) "320 pz 24.7"

write(10,22) "321 pz 27.0 $10"

write(10,22) "322 pz 27.4"

write(10,22) "323 pz 29.7 $11"

write(10,22) "324 pz 30.1"

write(10,22) "325 pz 32.4 $12"

write(10,22) "326 pz 32.8"

write(10,22) "327 pz 35.1 $13"

write(10,22) "328 pz 35.5"

write(10,22) "329 pz 37.8 $14"

write(10,22) "330 pz 38.2"

write(10,22) "331 pz 40.5 $15"

write(10,22) "332 pz 40.9"

write(10,22) "333 pz 43.2 $16"

write(10,22) "334 pz 43.6"

write(10,22) "335 pz 45.9 $17"

write(10,22) "336 pz 46.1"

write(10,22) "337 pz 47.9 $18"

write(10,22) "338 pz 48.1"

write(10,22) "339 pz 49.9 $19"

write(10,22) "340 pz 50.1"

write(10,22) "341 pz 51.9 $20"

write(10,22) "342 pz 52.1"

write(10,22) "343 pz 53.9 $21"

write(10,22) "344 pz 54.1"

write(10,22) "345 pz 55.9 $22"

write(10,22) "346 pz 56.1"

write(10,22) "347 pz 57.9 $23"

write(10,22) "348 pz 58.1"

write(10,22) "349 pz 59.9 $24"

write(10,22) "$Ribs"

!*********************
write(10,22) "$12Rib"

xsq2 = 0.0 + movx
ysq2 = 0.59 + movy

write(10,23) "400 sq 0.00308642 0.010519395 0 0 0 0 -1",xsq2,ysq2,"0 $in"

write(10,23) "401 sq 0.002878115 0.009263368 0 0 0 0 -1",xsq2,ysq2,"0 $out"

write(10,22) "402 pz 15 $313"

py1 = -2.0 + movy

write(10,24) "480 py",py1


!*********************
xsq3 = 0.0 + movx
ysq3 = 0.59 + movy

write(10,22) "$11Rib"

write(10,23) "403 sq 0.00308642 0.010519395 0 0 0 0 -1",xsq3,ysq3,"0 $in"

write(10,23) "404 sq 0.002878115 0.009263368 0 0 0 0 -1",xsq3,ysq3,"0 $out"

write(10,22) "405 pz 17.7 $315"

py2 = 0.55 + movy

write(10,24) "490 py",py2

!*********************
xsq4 = 0.0 + movx
ysq4 = 0.59 + movy

write(10,22) "$10Rib"

write(10,23) "406 sq 0.00308642 0.010519395 0 0 0 0 -1",xsq4,ysq4,"0 $in"

write(10,23) "407 sq 0.002878115 0.009263368 0 0 0 0 -1",xsq4,ysq4,"0 $out"

write(10,22) "408 pz 20.4 $317"

!*********************
xsq5 = 0.0 + movx
ysq5 = 0.57 + movy

write(10,22) "$9Rib"

write(10,23) "409 sq 0.003121945 0.010562685 0 0 0 0 -1",xsq5,ysq5,"0 $in"

write(10,23) "410 sq 0.002910096 0.009299134 0 0 0 0 -1",xsq5,ysq5,"0 $out"

write(10,22) "411 pz 23.1 $319"

!*********************
xsq6 = 0.0 + movx
ysq6 = 0.475 + movy

write(10,22) "$8Rib"

write(10,23) "412 sq 0.003233681 0.0107944 0 0 0 0 -1",xsq6,ysq6,"0 $in"

write(10,23) "413 sq 0.00300726 0.009471883 0 0 0 0 -1",xsq6,ysq6,"0 $out"

write(10,22) "414 pz 25.69 $321"

!*********************
xsq7 = 0.0 + movx
ysq7 = 0.405 + movy

write(10,22) "$7Rib"

write(10,23) "415 sq 0.003439128 0.01116243 0 0 0 0 -1",xsq7,ysq7,"0 $in"

write(10,23) "416 sq 0.003158999 0.009602272 0 0 0 0 -1",xsq7,ysq7,"0 $out"

write(10,22) "417 pz 28.42 $323"

!*********************

xsq8 = 0.0 + movx
ysq8 = 0.255 + movy

write(10,22) "$6Rib"

write(10,23) "418 sq 0.003729807 0.011574473 0 0 0 0 -1",xsq8,ysq8,"0 $in"

write(10,23) "419 sq 0.003406266 0.009890901 0 0 0 0 -1",xsq8,ysq8,"0 $out"

write(10,22) "420 pz 31.22 $325"

!*********************

xsq9 = 0.0 + movx
ysq9 = 0.05 + movy

write(10,22) "$5Rib"

write(10,23) "421 sq 0.00421031 0.011996607 0 0 0 0 -1",xsq9,ysq9,"0 $in"

write(10,23) "422 sq 0.003842857 0.010306888 0 0 0 0 -1",xsq9,ysq9,"0 $out"

write(10,22) "423 pz 33.96 $327"

!*********************

xsq10 = 0.0 + movx
ysq10 = -0.235 + movy

write(10,22) "$4Rib"

write(10,23) "424 sq 0.004827003 0.012667331 0 0 0 0 -1",xsq10,ysq10,"0 $in"

write(10,23) "425 sq 0.004401307 0.010930249 0 0 0 0 -1",xsq10,ysq10,"0 $out"

write(10,22) "426 pz 36.64 $329"

!*********************

xsq11 = 0.0 + movx
ysq11 = -0.65 + movy

write(10,22) "$3Rib"

write(10,23) "427 sq 0.006026361 0.013679423 0 0 0 0 -1",xsq11,ysq11,"0 $in"

write(10,23) "428 sq 0.005501892 0.01194422 0 0 0 0 -1",xsq11,ysq11,"0 $out"

write(10,22) "429 pz 39.37 $331"

!*********************

xsq12 = 0.0 + movx
ysq12 = -1.15 + movy

write(10,22) "$2Rib"

write(10,23) "430 sq 0.008361921 0.015431503 0 0 0 0 -1",xsq12,ysq12,"0 $in"

write(10,23) "431 sq 0.007514695 0.013364964 0 0 0 0 -1",xsq12,ysq12,"0 $out"

write(10,22) "432 pz 42.07 $333"

!*********************

xsq13 = 0.0 + movx
ysq13 = -2.1 + movy

write(10,22) "$1Rib"

write(10,23) "433 sq 0.018032466 0.019837334 0 0 0 0 -1",xsq13,ysq13,"0 $in"

write(10,23) "434 sq 0.015443598 0.016866251 0 0 0 0 -1",xsq13,ysq13,"0 $out"

write(10,22) "435 pz 44.77 $335"

!*********************

xsq14 = 0.0 + movx
ysq14 = 4.0 + movy

xsq15 = 0.0 + movx
ysq15 = 3.0 + movy


write(10,22) "$Sternum"

write(10,23) "450 sq 0.00444444 0.02040816 0.001609643 0 0 0 -1",xsq14,ysq14,"21.8"

write(10,23) "451 sq 0.00444444 0.02040816 0.001609643 0 0 0 -1",xsq15,ysq15,"21.8"


px3 = -2.0 + movx
px4 = 2.0 + movx

py3 = 0.0 + movy

write(10,24) "452 px",px3

write(10,24) "453 px",px4

write(10,22) "454 pz 25.6"

write(10,22) "455 pz 46.2"

write(10,24) "456 py",py3

!******************
rcx1 = 0.0 + movx
rcy1 = -6.5 + movy

write(10,22) "$Neck"

write(10,25) "500 RCC",rcx1,rcy1,"48 0 0 8 5"
25 format(A,X,F12.4,X,F12.4,X,A)

!******************


!******************
rcx2 = 0.0 + movx
rcy2 = -6.5 + movy

write(10,22) "$Neck-skin"

write(10,25) "501 RCC",rcx2,rcy2,"48 0 0 8 5.2045"
!25 format(A,X,F8.4,F8.4,X,A)

!******************
xsq16 = 0.0 + movx
ysq16 = -2.0 + movy

xsq17 = 0.0 + movx
ysq17 = -2.0 + movy

xsq18 = 0.0 + movx
ysq18 = -2.0 + movy

xsq19 = 0.0 + movx
ysq19 = -2.0 + movy


write(10,22) "$Face"

write(10,23) "600 sq 0.020408163 0.01384083 0.031956196 0 0 0 -1",xsq16,ysq16,"66.266 $in"

write(10,23) "601 sq 0.015625 0.011080332 0.022998638 0 0 0 -1",xsq17,ysq17,"66.266 $out"

write(10,23) "602 sq 0.020408163 0.01384083 0 0 0 0 -1",xsq18,ysq18,"0 $in-cylinder"

write(10,23) "603 sq 0.015625 0.011080332 0 0 0 0 -1",xsq19,ysq19,"0 $out-cylinder"


write(10,22) "604 pz 56"

write(10,22) "605 pz 66.266"

py4 = -0.605 + movy

write(10,24) "606 py",py4

!******************

xsq20 = 0.0 + movx
ysq20 = -2.0 + movy

xsq21 = 0.0 + movx
ysq21 = -2.0 + movy


write(10,22) "$Head-skin"

write(10,23) "608 sq 0.01485579 0.010618268 0.021635842 0 0 0 -1",xsq20,ysq20,"66.266 $out"

write(10,23) "609 sq 0.01485579 0.010618268 0 0 0 0 -1",xsq21,ysq21,"0 $out-cylinder"

write(10,22) "610 pz 55.7955"

!******************
rcx3 = -25.3290 + movx
rcy3 = 0.0 + movy
rcx4 = -25.3290 + movx
rcy4 = 0.0 + movy

write(10,22) "$Left-Arm"

write(10,25) "700 RCC",rcx3,rcy3,"-12 0 0 30 4 $Fore"
write(10,25) "701 RCC",rcx4,rcy4,"18 0 0 30 5 $Upper"

rcx5 = -25.3290 + movx
rcy5 = 0.0 + movy
rcx6 = -25.3290 + movx
rcy6 = 0.0 + movy

write(10,22) "$Left-Arm-bone"

write(10,25) "702 RCC",rcx5,rcy5,"-12 0 0 30 3 $Fore"
write(10,25) "703 RCC",rcx6,rcy6,"18 0 0 30 3 $Upper"

rcx7 = 25.3290 + movx
rcy7 = 0.0 + movy
rcx8 = 25.3290 + movx
rcy8 = 0.0 + movy

write(10,22) "$Right-Arm"

write(10,25) "704 RCC",rcx7,rcy7,"-12 0 0 30 4 $Fore"
write(10,25) "705 RCC",rcx8,rcy8,"18 0 0 30 5 $Upper"



rcx9 = 25.3290 + movx
rcy9 = 0.0 + movy
rcx10 = 25.3290 + movx
rcy10 = 0.0 + movy

write(10,22) "$Right-Arm-bone"

write(10,25) "706 RCC",rcx9,rcy9,"-12 0 0 30 3 $Fore"
write(10,25) "707 RCC",rcx10,rcy10,"18 0 0 30 3 $Upper"


!******************

write(10,22) "$Arms-skin"

rcx11 = -25.3290  + movx
rcy11 = 0.0 + movy
rcx12 = 25.3290 + movx
rcy12 = 0.0 + movy

write(10,25) "708 RCC",rcx11,rcy11,"-12.1290 0 0 30.1290 4.1290 $Left"
write(10,25) "709 RCC",rcx12,rcy12,"-12.1290 0 0 30.1290 4.1290 $Right"


!******************


rcx13 = -25.3290 + movx
rcy13 = 0.0 + movy
rcx14 = 25.3290 + movx
rcy14 = 0.0 + movy

write(10,25) "710 RCC",rcx13,rcy13,"18 0 0 30.1245 5.1245 $Left"
write(10,25) "711 RCC",rcx14,rcy14,"18 0 0 30.1245 5.1245 $Right"


!******************

write(10,22) "$Left-Leg"

rcx15 = -11 + movx
rcy15 = 0.0 + movy
rcx16 = -11 + movx
rcy16 = 0.0 + movy

write(10,25) "800 RCC",rcx15,rcy15,"-103.14 0 0 50.035 8 $Lower"
write(10,25) "801 RCC",rcx16,rcy16,"-53.105 0 0 50.035 9 $Thigh"


!******************

write(10,22) "$Left-Leg-bone"

rcx17 = -11 + movx
rcy17 = 0.0 + movy
rcx18 = -11 + movx
rcy18 = 0.0 + movy

write(10,25) "802 RCC",rcx17,rcy17,"-103.14 0 0 50.035 5 $Lower"
write(10,25) "803 RCC",rcx18,rcy18,"-53.105 0 0 50.035 5 $Thigh"


!******************

!******************

write(10,22) "$Right-Leg"

rcx19 = 11 + movx
rcy19 = 0.0 + movy
rcx20 = 11 + movx
rcy20 = 0.0 + movy

write(10,25) "804 RCC",rcx19,rcy19,"-103.14 0 0 50.035 8 $Lower"
write(10,25) "805 RCC",rcx20,rcy20,"-53.105 0 0 50.035 9 $Thigh"


!******************

write(10,22) "$Right-Leg-bone"

rcx21 = 11 + movx
rcy21 = 0.0 + movy
rcx22 = 11 + movx
rcy22 = 0.0 + movy

write(10,25) "806 RCC",rcx21,rcy21,"-103.14 0 0 50.035 5 $Lower"
write(10,25) "807 RCC",rcx22,rcy22,"-53.105 0 0 50.035 5 $Thigh"


!******************


!******************

write(10,22) "$Leg-skin"

rcx23 = -11 + movx
rcy23 = 0.0 + movy
rcx24 = 11 + movx
rcy24 = 0.0 + movy

write(10,25) "808 RCC",rcx23,rcy23,"-103.269 0 0 50.164 8.1290 $Left"
write(10,25) "809 RCC ",rcx24,rcy24,"-103.269 0 0 50.164 8.1290 $Right"


!******************

write(10,22) "$Thigh"

rcx25 = -11 + movx
rcy25 = 0.0 + movy
rcx26 = 11 + movx
rcy26 = 0.0 + movy

write(10,25) "810 RCC",rcx25,rcy25,"-53.105 0 0 50.035 9.1245 $Left"
write(10,25) "811 RCC",rcx26,rcy26,"-53.105 0 0 50.035 9.1245 $Right"


!******************


write(10,22) "$Trunk"

xsq22 = 0.0 + movx
ysq22 = 0.0 + movy


write(10,23) "900 sq 0.0025 0.00756144 0 0 0 0 -1",xsq22,ysq22,"0"

write(10,22) "901 pz -3.07"

write(10,22) "902 pz 48"


!******************


write(10,22) "$Trunk-skin"

xsq23 = 0.0 + movx
ysq23 = 0.0 + movy


write(10,23) "903 sq 0.002449649 0.007299523 0 0 0 0 -1",xsq22,ysq22,"0"

write(10,22) "904 pz -3.2745"

write(10,22) "905 pz 48.2045"



write(10,22) "$Outer-boundary"

sor = 500.0*step

write(10,29) "990 so", sor
29 format(A,X,F12.4)

write(10,*) " "

!******************

write(10,21) adjustl(trim("[ C e l l ]"))

write(10,22) "990    -1     990"

write(10,22) "$Left-Lung"

rho1 = -0.26 !lung

write(10,188) "100 4",rho1,"-100 -101 102 200"
188 format(A,X,F8.4,X,A)

write(10,188) "101 4",rho1,"-110 111 112 200"

rho2 = -1.05 !heart

write(10,188) "200 2",rho2,"-210 211 $heart-tissue "

rho3 = -1.06 !blood

write(10,188) "201 3",rho3,"-211 $blood"

!**********************

write(10,22) "$Spine"

rho4 = -1.10 !disc
rho5 = -1.33 !vertebrae

write(10,188) "300 15",rho4,"-300 301 -302 $Disc-24"
write(10,188) "301 14",rho5,"-300 302 -303 $Vertebrae-lumbale-5"


write(10,188) "302 15",rho4,"-300 303 -304 $Disc-23"
write(10,188) "303 14",rho5,"-300 304 -305 $Vertebrae-lumbale-4"


write(10,188) "304 15",rho4,"-300 305 -306 $Disc-22"
write(10,188) "305 14",rho5,"-300 306 -307 $Vertebrae-lumbale-3"


write(10,188) "306 15",rho4,"-300 307 -308 $Disc-21"
write(10,188) "307 14",rho5,"-300 308 -309 $Vertebrae-lumbale-2"


write(10,188) "308 15",rho4,"-300 309 -310 $Disc-20"
write(10,188) "309 14",rho5,"-300 310 -311 $Vertebrae-lumbale-1"


write(10,188) "310 15",rho4,"-300 311 -312 $Disc-19"
write(10,188) "311 14",rho5,"-300 312 -313 $Thoracic-vertebrae-2"


write(10,188) "312 15",rho4,"-300 313 -314 $Disc-18"
write(10,188) "313 14",rho5,"-300 314 -315 $Thoracic-vertebrae-11"


write(10,188) "314 15",rho4,"-300 315 -316 $Disc-17"
write(10,188) "315 14",rho5,"-300 316 -317 $Thoracic-vertebrae-10"


write(10,188) "316 15",rho4,"-300 317 -318 $Disc-16"
write(10,188) "317 14",rho5,"-300 318 -319 $Thoracic-vertebrae-9"


write(10,188) "318 15",rho4,"-300 319 -320 $Disc-15"
write(10,188) "319 14",rho5,"-300 320 -321 $Thoracic-vertebrae-8"


write(10,188) "320 15",rho4,"-300 321 -322 $Disc-14"
write(10,188) "321 14",rho5,"-300 322 -323 $Thoracic-vertebrae-7"


write(10,188) "322 15",rho4,"-300 323 -324 $Disc-13"
write(10,188) "323 14",rho5,"-300 324 -325 $Thoracic-vertebrae-6"


write(10,188) "324 15",rho4,"-300 325 -326 $Disc-12"
write(10,188) "325 14",rho5,"-300 326 -327 $Thoracic-vertebrae-5"


write(10,188) "326 15",rho4,"-300 327 -328 $Disc-11"
write(10,188) "327 14",rho5,"-300 328 -329 $Thoracic-vertebrae-4"


write(10,188) "328 15",rho4,"-300 329 -330 $Disc-10"
write(10,188) "329 14",rho5,"-300 330 -331 $Thoracic-vertebrae-3"


write(10,188) "330 15",rho4,"-300 331 -332 $Disc-9"
write(10,188) "331 14",rho5,"-300 332 -333 $Thoracic-vertebrae-2"


write(10,188) "332 15",rho4,"-300 333 -334 $Disc-8"
write(10,188) "333 14",rho5,"-300 334 -335 $Thoracic-vertebrae-1"

rho6 = -1.42 !vertebrae up

write(10,188) "334 15",rho4,"-300 335 -336 $Disc-7"
write(10,188) "335 13",rho6,"-300 336 -337 $Cervical-vertebrae-7"


write(10,188) "336 15",rho4,"-300 337 -338 $Disc-6"
write(10,188) "337 13",rho6,"-300 338 -339 $Cervical-vertebrae-6"


write(10,188) "338 15",rho4,"-300 339 -340 $Disc-5"
write(10,188) "339 13",rho6,"-300 340 -341 $Cervical-vertebrae-5"


write(10,188) "340 15",rho4,"-300 341 -342 $Disc-4"
write(10,188) "341 13",rho6,"-300 342 -343 $Cervical-vertebrae-4"


write(10,188) "342 15",rho4,"-300 343 -344 $Disc-3"
write(10,188) "343 13",rho6,"-300 344 -345 $Cervical-vertebrae-3"


write(10,188) "344 15",rho4,"-300 345 -346 $Disc-2"
write(10,188) "345 13",rho6,"-300 346 -347 $Cervical-vertebrae-2"


write(10,188) "346 15",rho4,"-300 347 -348 $Disc-1"
write(10,188) "347 13",rho6,"-300 348 -349 $Cervical-vertebrae-1"


write(10,22) "$Rib-cage"

rho7 = -1.52 !********
rho8 = -1.41 !********

write(10,188) "400 12",rho7,"300 400 -401 402 -313 -480 $Rib12"

write(10,188) "401 12",rho7,"300 403 -404 405 -315 -490 $Rib11"

write(10,188) "402 12",rho7,"300 406 -407 408 -317 $Rib10"

write(10,188) "403 11",rho8,"300 409 -410 411 -319 $Rib9"

write(10,188) "404 11",rho8,"300 412 -413 414 -321 $Rib8"

write(10,188) "405 11",rho8,"300 415 -416 417 -323 $Rib7"

write(10,188) "406 11",rho8,"300 418 -419 420 -325 $Rib6"

write(10,188) "407 11",rho8,"300 421 -422 423 -327 $Rib5"

write(10,188) "408 11",rho8,"300 424 -425 426 -329 $Rib4"

write(10,188) "409 11",rho8,"300 427 -428 429 -331 $Rib3"

write(10,188) "410 11",rho8,"300 430 -431 432 -333 $Rib2"

write(10,188) "411 11",rho8,"300 433 -434 435 -335 $Rib1"

!**************************************

write(10,22) "$Sternum"

rho9 = -1.03 !mat 1 density
rho10 = -1.09 !mat 6 density


write(10,188) "450 11",rho8,"-450 451 452 -453 454 -455 456 #404 #405 #406 #407 #408 #409 #410 #411"

write(10,22) "$Neck"

write(10,188) "500 1",rho9,"-500 #335 #336 #337 #338 #339 #340 #341 #342 #343 #344 #345 #346 #347"

write(10,188) "501 6",rho10,"500 -501 $Neck-skin"

!**************************************

write(10,22) "$Head-Neck"

rho11 = -1.61 !mat 7 density
rho12 = -1.04 !mat 5 density
rho13 = -1.68 !mat 10 density
rho14 = -1.09 !mat 6 density


write(10,188) "600 7",rho11,"600 -601 $Skull"

write(10,188) "601 5",rho12,"-600 $ Brain"

write(10,188) "602 10",rho13,"602 -603 -605 604 606 #600 $Facial-bone"

write(10,188) "603 1",rho9,"-603 -605 604 #600 #601 #602 #344 #345 #346 #347 $Soft-tissue"

write(10,188) "604 6",rho14,"-608 601 605 $Head-skin"

write(10,188) "605 6",rho14,"-609 603 604 -605 $Face-skin"

write(10,188) "606 6",rho14,"-609 -604 610 #344 #345 #346 #347 #500 #501 $Lower-face-skin"

!**************************************

write(10,22) "$Arms"

rho15 = -1.46 !mat 9 density

write(10,188) "700 1",rho9,"-700 702 $Left-arm-soft-tissue"

write(10,188) "701 1",rho9,"-701 703 $Left-arm-soft-tissue"

write(10,188) "702 9",rho15,"-702 $Lower-Left-bone"

write(10,188) "703 9",rho15,"-703 $ Upper-Left-bone"

write(10,188) "704 1",rho9,"-704 706 $Lower-Right-tissue"

write(10,188) "705 1",rho9,"-705 707 $Upper-Right-tissue"

write(10,188) "706 9",rho15,"-706 $Lower-Right-bone"

write(10,188) "707 9",rho15,"-707 $Upper-Right-bone"


write(10,22) "$Arms-skin"

write(10,188) "708 6",rho10,"700 -708 $Lower-left"

write(10,188) "709 6",rho10,"704 -709 $Lower-right"

write(10,188) "710 6",rho10,"701 -710 $Upper-left"

write(10,188) "711 6",rho10,"705 -711 $Upper-right"


write(10,22) "$Legs"

rho16 = -1.33 !mat 8 density


write(10,188) "800 1",rho9,"-800 802"

write(10,188) "801 1",rho9,"-801 803"

write(10,188) "802 8",rho16,"-802"

write(10,188) "803 8",rho16,"-803"

write(10,188) "804 1",rho9,"-804 806"

write(10,188) "805 1",rho9,"-805 807"

write(10,188) "806 8",rho16,"-806"

write(10,188) "807 8",rho16,"-807"


write(10,22) "$Legs-skin"


write(10,188) "808 6",rho14,"800 -808 $Lower-left"

write(10,188) "809 6",rho14,"804 -809 $Lower-right"

write(10,188) "810 6",rho14,"801 -810 $Upper-left"

write(10,188) "811 6",rho14,"805 -811 $Upper-right"


write(10,22) "$Trunk"

write(10,188) "900 1",rho9,"-900 901 -902 #100 #101 #200 #201 #300 #301 #302 #303 #304 #305"

write(10,22) "                          #306 #307 #308 #309 #310 #311 #312 #313 #314 #315"
write(10,22) "                          #316 #317 #318 #319 #320 #321 #322 #323 #324 #325"
write(10,22) "                          #326 #327 #328 #329 #330 #331 #332 #333 #334 #335"
write(10,22) "                          #336 #337 #338 #339 #340 #341 #342 #343 #344 #345"
write(10,22) "                          #346 #347 #400 #401 #402 #403 #404 #405 #406 #407"
write(10,22) "                          #408 #409 #410 #411 #450"

write(10,22) "$Trunk-skin"


write(10,188) "901 6",rho14,"900 -903 901 -902"

write(10,188) "902 6",rho14,"-903 904 -901 #801 #803 #805 #807 #810 #811"

write(10,188) "903 6",rho14,"-903 902 -905 #344 #345 #346 #347 #500 #501"

if(shield==1)then
write(10,22) "$Shield"
write(10,226) "910  18",shieldrho*(-1.),"-910"
226 format(A,X,F8.4,X,A)

write(10,22) "$Vaccuum-Air"

write(10,22) "991 16 -0.00129 -990 #100 #101 #200 #201 #300 #301 #302 #303 #304 #305 #306 #307 #308"
write(10,22) "           #309 #310 #311 #312 #313 #314 #315 #316 #317 #318 #319 #320 #321"
write(10,22) "           #322 #323 #324 #325 #326 #327 #328 #329 #330 #331 #332 #333 #334"
write(10,22) "           #335 #336 #337 #338 #339 #340 #341 #342 #343 #344 #345 #346 #347"
write(10,22) "           #400 #401 #402 #403 #404 #405 #406 #407 #408 #409 #410 #411 #450"
write(10,22) "           #500 #501 #600 #601 #602 #603 #604 #605 #606 #700 #701 #702 #703"
write(10,22) "           #704 #705 #706 #707 #708 #709 #710 #711 #800 #801 #802 #803 #804"
write(10,22) "           #805 #806 #807 #808 #809 #810 #811 #900 #901 #902 #903 #910"


else
write(10,22) "$Vaccuum-Air"

write(10,22) "991 16 -0.00129 -990 #100 #101 #200 #201 #300 #301 #302 #303 #304 #305 #306 #307 #308"
write(10,22) "           #309 #310 #311 #312 #313 #314 #315 #316 #317 #318 #319 #320 #321"
write(10,22) "           #322 #323 #324 #325 #326 #327 #328 #329 #330 #331 #332 #333 #334"
write(10,22) "           #335 #336 #337 #338 #339 #340 #341 #342 #343 #344 #345 #346 #347"
write(10,22) "           #400 #401 #402 #403 #404 #405 #406 #407 #408 #409 #410 #411 #450"
write(10,22) "           #500 #501 #600 #601 #602 #603 #604 #605 #606 #700 #701 #702 #703"
write(10,22) "           #704 #705 #706 #707 #708 #709 #710 #711 #800 #801 #802 #803 #804"
write(10,22) "           #805 #806 #807 #808 #809 #810 #811 #900 #901 #902 #903"

end if


write(10,*) " "



if(coord==0)then

!***************
write(10,37) adjustl(trim("[ T - Gshow ]"))
37 format(A)

write(10,38) adjustl(trim("    title = generated human phantom xz"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    z-type =    2"))

38 format(3X,A)

write(10,39) adjustl(trim("    zmin =  ")), -120.0

write(10,39) adjustl(trim("    zmax =  ")), 120.0
39 format(3X,A,X,F12.4)

write(10,38) adjustl(trim("    nz =   200"))

write(10,38) adjustl(trim("    x-type =    2"))

write(10,39) adjustl(trim("    xmin =  ")), px-30.0

write(10,39) adjustl(trim("    xmax =  ")), px+30.0

write(10,38) adjustl(trim("    nx =   100"))

write(10,38) adjustl(trim("    y-type =    1"))

write(10,38) adjustl(trim("    ny =    1"))

write(10,40) py-30.0, py+30.0
40 format(3X,F8.3,X,F8.3)

write(10,38) adjustl(trim("axis =   xz"))

write(10,38) adjustl(trim("file = front_view.out"))

write(10,38) adjustl(trim("output =    2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "

write(10,37) adjustl(trim("[ T - Gshow ]"))
!37 format(A)

write(10,38) adjustl(trim("    title = generated human phantom xy"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    x-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    xmin =  ")), px-30.0

write(10,39) adjustl(trim("    xmax =  ")), px+30.0
!39 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("    nx =   200"))

write(10,38) adjustl(trim("    y-type =    2"))

write(10,39) adjustl(trim("    ymin =  ")), py-30.0

write(10,39) adjustl(trim("    ymax =  ")), py+30.0

write(10,38) adjustl(trim("    ny =   100"))

write(10,38) adjustl(trim("    z-type =    1"))

write(10,38) adjustl(trim("    nz =    1"))

write(10,40) -120.0, 120.0 
!40 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("axis =   xy"))

write(10,38) adjustl(trim("file = top_view.out"))

write(10,38) adjustl(trim("output =    2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "


write(10,37) adjustl(trim("[ T - Gshow ]"))
!37 format(A)

write(10,38) adjustl(trim("    title = generated human phantom yz"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    z-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    zmin =  ")), -120.0

write(10,39) adjustl(trim("    zmax =  ")), 120.0
!39 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("    nz =   200"))

write(10,38) adjustl(trim("    y-type =    2"))

write(10,39) adjustl(trim("    ymin =  ")), py-30.0

write(10,39) adjustl(trim("    ymax =  ")), py+30.0

write(10,38) adjustl(trim("    ny =   100"))

write(10,38) adjustl(trim("    x-type =    1"))

write(10,38) adjustl(trim("    nx =    1"))

write(10,40) px-30.0, px+30.0 
!40 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("axis =   yz"))

write(10,38) adjustl(trim("file = side_view.out"))

write(10,38) adjustl(trim("output =    2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "
!***************

do i = 1,ntally

write(10,37) adjustl(trim("[ T - Deposit ]"))
!37 format(A)

write(10,38) adjustl(trim("    title = dose human phantom xy"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    x-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    xmin =  ")), px-30.0

write(10,39) adjustl(trim("    xmax =  ")), px+30.0
!39 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("    nx =   200"))

write(10,38) adjustl(trim("    y-type =    2"))

write(10,39) adjustl(trim("    ymin =  ")), py-30.0

write(10,39) adjustl(trim("    ymax =  ")), py+30.0

write(10,38) adjustl(trim("    ny =   100"))

write(10,38) adjustl(trim("    z-type =    1"))

write(10,38) adjustl(trim("    nz =    1"))

write(10,40) -120.0, 120.0 
!40 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("axis =   xy"))

write(10,838) adjustl(trim("file = top_view_deposit_")),trim(tally(i)),trim(".out")
838 format(3X,A,A,A)


write(10,738) adjustl(trim("part  =  ")),trim(tally(i))
738 format(3X,A,X,A)

write(10,38) adjustl(trim("material  =  all"))

write(10,38) adjustl(trim("output =    dose"))

write(10,38) adjustl(trim("unit =    2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "



write(10,37) adjustl(trim("[ T - Deposit ]"))
!37 format(A)

write(10,38) adjustl(trim("    title = dose human phantom yz"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    z-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    zmin =  ")), -120.0

write(10,39) adjustl(trim("    zmax =  ")), 120.0
!39 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("    nz =   200"))

write(10,38) adjustl(trim("    y-type =    2"))

write(10,39) adjustl(trim("    ymin =  ")), py-30.0

write(10,39) adjustl(trim("    ymax =  ")), py+30.0

write(10,38) adjustl(trim("    ny =   100"))

write(10,38) adjustl(trim("    x-type =    1"))

write(10,38) adjustl(trim("    nx =    1"))

write(10,40) px-30.0, px+30.0 
!40 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("axis =   yz"))

write(10,838) adjustl(trim("file = side_view_deposit_")),trim(tally(i)),trim(".out")

write(10,738) adjustl(trim("part  =  ")),trim(tally(i))

write(10,38) adjustl(trim("material  =  all"))

write(10,38) adjustl(trim("output =    dose"))

write(10,38) adjustl(trim("unit =    2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "

write(10,37) adjustl(trim("[ T - Deposit ]"))

write(10,38) adjustl(trim("    title = dose human phantom xz"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    z-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    zmin =  ")), -120.0

write(10,39) adjustl(trim("    zmax =  ")), 120.0
!39 format(3X,A,X,F12.4)

write(10,38) adjustl(trim("    nz =   200"))

write(10,38) adjustl(trim("    x-type =    2"))

write(10,39) adjustl(trim("    xmin =  ")), px-30.0

write(10,39) adjustl(trim("    xmax =  ")), px+30.0

write(10,38) adjustl(trim("    nx =   100"))

write(10,38) adjustl(trim("    y-type =    1"))

write(10,38) adjustl(trim("    ny =    1"))

write(10,40) py-30.0, py+30.0
!40 format(3X,F8.3,X,F8.3)

write(10,38) adjustl(trim("axis =   xz"))

write(10,838) adjustl(trim("file = front_view_deposit_")),trim(tally(i)),trim(".out")

write(10,738) adjustl(trim("part  =  ")),trim(tally(i))

write(10,38) adjustl(trim("material  =  all"))

write(10,38) adjustl(trim("output =    dose"))

write(10,38) adjustl(trim("unit =    2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "

write(10,37) adjustl(trim("[ T - Deposit ]"))

write(10,38) adjustl(trim("    title = selected organ doses in Gy/source"))

write(10,38) adjustl(trim("    mesh =  reg"))

write(10,38) adjustl(trim("    reg = 100 101 ( 200 201 ) ( { 300-347 } ) 601 ( { 604-606 } )"))


write(10,38) adjustl(trim("    volume"))
write(10,38) adjustl(trim("    reg      vol"))
write(10,38) adjustl(trim("    100      2.1595E+03  #L-lung"))
write(10,38) adjustl(trim("    101      2.4672E+03  #R-lung"))
write(10,38) adjustl(trim("    1000001  8.1061E+02  #heart-tissue-blood"))
write(10,38) adjustl(trim("    1000002  7.1064E+02  #spine-and-discs"))
write(10,38) adjustl(trim("    601      1.3751E+03  #brain"))
write(10,38) adjustl(trim("    1000003  2.2932E+02  #head-face-skin"))

write(10,38) adjustl(trim("axis =   reg"))

write(10,838) adjustl(trim("file = organ_deposit_")),trim(tally(i)),trim(".out")

write(10,38) adjustl(trim("unit  =  0"))

write(10,738) adjustl(trim("part  =  ")),trim(tally(i))

write(10,38) adjustl(trim("material  =  all"))

write(10,38) adjustl(trim("output =    dose"))

write(10,38) adjustl(trim("epsout =    1"))

write(10,*) " "

end do


elseif(coord==1)then

!***************
write(10,37) adjustl(trim("[ T - Gshow ]"))
!37 format(A)

write(10,38) adjustl(trim("    title = generated human phantom xz"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    z-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    zmin =  ")), -120.0

write(10,39) adjustl(trim("    zmax =  ")), 120.0
!39 format(3X,A,X,F12.4)

write(10,38) adjustl(trim("    nz =   200"))

write(10,38) adjustl(trim("    x-type =    2"))

write(10,39) adjustl(trim("    xmin =  ")), 0.0

write(10,39) adjustl(trim("    xmax =  ")), step*200.

write(10,38) adjustl(trim("    nx =   100"))

write(10,38) adjustl(trim("    y-type =    1"))

write(10,38) adjustl(trim("    ny =    1"))

write(10,40) 0.0, step*200.
!40 format(3X,F8.3,X,F8.3)

write(10,38) adjustl(trim("axis =   xz"))

write(10,38) adjustl(trim("file = front_view.out"))

write(10,38) adjustl(trim("output =    2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "

write(10,37) adjustl(trim("[ T - Gshow ]"))
!37 format(A)

write(10,38) adjustl(trim("    title = generated human phantom xy"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    x-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    xmin =  ")), 0.0

write(10,39) adjustl(trim("    xmax =  ")), step*200.
!39 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("    nx =   200"))

write(10,38) adjustl(trim("    y-type =    2"))

write(10,39) adjustl(trim("    ymin =  ")), 0.0

write(10,39) adjustl(trim("    ymax =  ")), step*200.

write(10,38) adjustl(trim("    ny =   100"))

write(10,38) adjustl(trim("    z-type =    1"))

write(10,38) adjustl(trim("    nz =    1"))

write(10,40) -120.0, 120.0 
!40 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("axis =   xy"))

write(10,38) adjustl(trim("file = top_view.out"))

write(10,38) adjustl(trim("output =    2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "


write(10,37) adjustl(trim("[ T - Gshow ]"))
!37 format(A)

write(10,38) adjustl(trim("    title = generated human phantom yz"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    z-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    zmin =  ")), -120.0

write(10,39) adjustl(trim("    zmax =  ")), 120.0
!39 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("    nz =   200"))

write(10,38) adjustl(trim("    y-type =    2"))

write(10,39) adjustl(trim("    ymin =  ")), 0.0

write(10,39) adjustl(trim("    ymax =  ")), step*200.

write(10,38) adjustl(trim("    ny =   100"))

write(10,38) adjustl(trim("    x-type =    1"))

write(10,38) adjustl(trim("    nx =    1"))

write(10,40) 0.0, step*200. 
!40 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("axis =   yz"))

write(10,38) adjustl(trim("file = side_view.out"))

write(10,38) adjustl(trim("output =    2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "
!***************

do i = 1,ntally

write(10,37) adjustl(trim("[ T - Deposit ]"))
!37 format(A)

write(10,38) adjustl(trim("    title = dose human phantom xy"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    x-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    xmin =  ")), 0.00

write(10,39) adjustl(trim("    xmax =  ")), step*200.
!39 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("    nx =   200"))

write(10,38) adjustl(trim("    y-type =    2"))

write(10,39) adjustl(trim("    ymin =  ")), 0.00

write(10,39) adjustl(trim("    ymax =  ")), step*200.

write(10,38) adjustl(trim("    ny =   100"))

write(10,38) adjustl(trim("    z-type =    1"))

write(10,38) adjustl(trim("    nz =    1"))

write(10,40) -120.0, 120.0 
!40 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("axis =   xy"))

write(10,838) adjustl(trim("file = top_view_deposit_")),trim(tally(i)),trim(".out")
!838 format(3X,A,A,A)


write(10,738) adjustl(trim("part  =  ")),trim(tally(i))
!738 format(3X,A,X,A)

write(10,38) adjustl(trim("material  =  all"))

write(10,38) adjustl(trim("output =    dose"))

write(10,38) adjustl(trim("unit  =  2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "



write(10,37) adjustl(trim("[ T - Deposit ]"))
!37 format(A)

write(10,38) adjustl(trim("    title = dose human phantom yz"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    z-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    zmin =  ")), -120.0

write(10,39) adjustl(trim("    zmax =  ")), 120.0
!39 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("    nz =   200"))

write(10,38) adjustl(trim("    y-type =    2"))

write(10,39) adjustl(trim("    ymin =  ")), 0.00

write(10,39) adjustl(trim("    ymax =  ")), step*200.

write(10,38) adjustl(trim("    ny =   100"))

write(10,38) adjustl(trim("    x-type =    1"))

write(10,38) adjustl(trim("    nx =    1"))

write(10,40) 0.00, step*200.
!40 format(3X,A,X,F8.3)

write(10,38) adjustl(trim("axis =   yz"))

write(10,838) adjustl(trim("file = side_view_deposit_")),trim(tally(i)),trim(".out")

write(10,738) adjustl(trim("part  =  ")),trim(tally(i))

write(10,38) adjustl(trim("material  =  all"))

write(10,38) adjustl(trim("output =    dose"))

write(10,38) adjustl(trim("unit  =  2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "

write(10,37) adjustl(trim("[ T - Deposit ]"))

write(10,38) adjustl(trim("    title = dose human phantom xz"))

write(10,38) adjustl(trim("    mesh =  xyz"))

write(10,38) adjustl(trim("    z-type =    2"))

!38 format(3X,A)

write(10,39) adjustl(trim("    zmin =  ")), -120.0

write(10,39) adjustl(trim("    zmax =  ")), 120.0
!39 format(3X,A,X,F12.4)

write(10,38) adjustl(trim("    nz =   200"))

write(10,38) adjustl(trim("    x-type =    2"))

write(10,39) adjustl(trim("    xmin =  ")), 0.00

write(10,39) adjustl(trim("    xmax =  ")), step*200.

write(10,38) adjustl(trim("    nx =   100"))

write(10,38) adjustl(trim("    y-type =    1"))

write(10,38) adjustl(trim("    ny =    1"))

write(10,40) 0.00, step*200.
!40 format(3X,F8.3,X,F8.3)

write(10,38) adjustl(trim("axis =   xz"))

write(10,838) adjustl(trim("file = front_view_deposit_")),trim(tally(i)),trim(".out")

write(10,738) adjustl(trim("part  =  ")),trim(tally(i))

write(10,38) adjustl(trim("material  =  all"))

write(10,38) adjustl(trim("output =    dose"))

write(10,38) adjustl(trim("unit  =  2"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "

write(10,37) adjustl(trim("[ T - Deposit ]"))

write(10,38) adjustl(trim("    title = selected organ doses in Gy/source"))

write(10,38) adjustl(trim("    mesh =  reg"))

write(10,38) adjustl(trim("    reg = 100 101 ( 200 201 ) ( { 300-347 } ) 601 ( { 604-606 } )"))


write(10,38) adjustl(trim("    volume"))
write(10,38) adjustl(trim("    reg      vol"))
write(10,38) adjustl(trim("    100      2.1595E+03  #L-lung"))
write(10,38) adjustl(trim("    101      2.4672E+03  #R-lung"))
write(10,38) adjustl(trim("    1000001  8.1061E+02  #heart-tissue-blood"))
write(10,38) adjustl(trim("    1000002  7.1064E+02  #spine-and-discs"))
write(10,38) adjustl(trim("    601      1.3751E+03  #brain"))
write(10,38) adjustl(trim("    1000003  2.2932E+02  #head-face-skin"))

write(10,38) adjustl(trim("axis =   reg"))

write(10,838) adjustl(trim("file = organ_deposit_")),trim(tally(i)),trim(".out")

write(10,38) adjustl(trim("unit  =  0"))

write(10,738) adjustl(trim("part  =  ")),trim(tally(i))

write(10,38) adjustl(trim("material  =  all"))

write(10,38) adjustl(trim("output =    dose"))

write(10,38) adjustl(trim("epsout =    1"))


write(10,*) " "


end do



end if

write(10,22) "#organ region table"
write(10,22) "#No.  reg    organ(s)"
write(10,22) "#1     100    left-lung"
write(10,22) "#2     101    right-lung"
write(10,22) "#3   200 201  heart-tissue-blood"
write(10,22) "#4   300-347  spine-and-discs"
write(10,22) "#5     601    brain"
write(10,22) "#6   604-606  head-face-skin"

write(10,*) " "

write(10,22) "[END]"


open(555,file='script.inp')
write(555,*) adjustl(trim(gg))
close(555)



deallocate(tally)

end do

deallocate(sxar)
deallocate(syar)
deallocate(szar)
deallocate(pxar)
deallocate(pyar)

end program manualentry