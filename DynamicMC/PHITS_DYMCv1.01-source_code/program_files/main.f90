program PHITSDYMC
implicit none


call codegen

call system("./pointsfind.exe")

!call system("./sumtally.exe")

!call system("sh runphits.bat")

!call system("rm *.tmp")





end program PHITSDYMC
