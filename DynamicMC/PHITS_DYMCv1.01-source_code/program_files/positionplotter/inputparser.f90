program main
integer :: i,nline
real*4,dimension(:),allocatable :: sx,sy,sz,px,py
character(256) :: headerchar
real*4 :: maxvaluex1,maxvaluex2,maxvaluey1,maxvaluey2
real*4 :: maxx,maxy


open(20,file='manlines.tmp')
read(20,*) nline
close(20)

allocate(sx(nline))
allocate(sy(nline))
allocate(sz(nline))
allocate(px(nline))
allocate(py(nline))

open(22,file='manualinp.tmp')
read(22,*) headerchar
do i=1,nline
read(22,*) sx(i),sy(i),sz(i),px(i),py(i)
end do
close(22)


open(10,file='dataplot.tmp')
do i=1,nline
write(10,*) sx(i),sy(i),px(i),py(i)
end do
close(10)


maxvaluex1 = maxval(sx)
maxvaluex2 = maxval(px)

!the max will be used to set the range for the cyricpositionplotter
if(maxvaluex1>maxvaluex2)then
maxx= maxvaluex1
else
maxx = maxvaluex2
end if


maxvaluey1 = maxval(sy)
maxvaluey2 = maxval(py)

!the max will be used to set the range for the cyricpositionplotter
if(maxvaluey1>maxvaluey2)then
maxy= maxvaluey1
else
maxy = maxvaluey2
end if

open(11,file='maxvalues.tmp')
write(11,*) maxx, maxy
close(11)

print*, maxx, maxy


end program main