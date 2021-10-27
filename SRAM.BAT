SET PATH=D:\programfile\KEIL5\ARM\ARMCC\Bin;C:\Program Files (x86)\Intel\iCLS Client\;C:\Program Files\Intel\iCLS Client\;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\Intel\WiFi\bin\;C:\Program Files\Common Files\Intel\WirelessCommon\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files\Intel\Intel(R) Management Engine Components\DAL;C:\Program Files (x86)\Intel\Intel(R) Management Engine Components\IPT;C:\Program Files\Intel\Intel(R) Management Engine Components\IPT;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;D:\programfile\matlab2016\runtime\win64;D:\programfile\matlab2016\bin;D:\programfile\matlab2016\polyspace\bin;C:\Program Files (x86)\STMicroelectronics\STM32 ST-LINK Utility\ST-LINK Utility;C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Bin\;C:\Program Files\IVI Foundation\VISA\Win64\Bin\;C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Bin;D:\programfile\maven\apache-maven-3.8.3\bin;D:\programfile\JAVAVA\jdk-904\bin;D:\programfile\MinGW\mingw64\bin;D:\programfile\python3-6\Scripts\;D:\programfile\python3-6\;C:\Users\lilun\AppData\Local\Microsoft\WindowsApps;C:\Program Files\Bandizip\;C:\Users\lilun\AppData\Local\Programs\Microsoft VS Code\bin;D:\programfile\KEIL5\ARM\ARMCC\bin;
SET ARMCC5_ASMOPT=--diag_suppress=9931
SET ARMCC5_CCOPT=--diag_suppress=9931
SET ARMCC5_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=STM32F407VE
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=SRAM
SET CPU_CLOCK=0x00B71B00
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\main.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_it.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\system_stm32f4xx.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\can.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\delay.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\sys.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\usart.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmAsm" --Via ".\objects\startup_stm32f40_41xxx._ia"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\misc.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_gpio.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_rcc.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_syscfg.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_usart.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_can.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stm32f4xx_spi.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\croutine.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\event_groups.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\list.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\queue.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\stream_buffer.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\tasks.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\timers.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\heap_4.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\port.__i"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\ArmLink" --Via ".\Objects\SRAM.lnp"
"D:\programfile\KEIL5\ARM\ARMCC\Bin\fromelf.exe" ".\Objects\SRAM.axf" --i32combined --output ".\Objects\SRAM.hex"
