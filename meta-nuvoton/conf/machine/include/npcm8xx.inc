#@TYPE: Machine
#@NAME: Nuvoton NPCM8XX
#@DESCRIPTION: Common machine configuration for Nuvoton NPCM8XX Chip

require conf/machine/include/nuvoton.inc
require conf/machine/include/igps-keys.inc

KERNEL_IMAGETYPE ?= "Image"

KERNEL_IMAGETYPE:df-obmc-static-norootfs = "Image"
KERNEL_IMAGETYPES:df-obmc-static-norootfs = "${KERNEL_IMAGETYPE}"

KERNEL_EXTRA_ARGS ?= "UIMAGE_LOADADDR=0x00008000"

UBOOT_MACHINE ?= "ArbelEVB_defconfig"
UBOOT_ENTRYPOINT ?= "0x6200000"
UBOOT_LOADADDRESS ?= "0x6200000"

FLASH_SIZE ?= "32768"
FLASH_UBOOT_OFFSET ?= "0"
FLASH_UBOOT_ENV_OFFSET = "1024"
FLASH_KERNEL_OFFSET ?= "2048"
FLASH_ROFS_OFFSET ?= "8192"
FLASH_RWFS_OFFSET ?= "31744"

# UBI volume sizes in KB unless otherwise noted.
FLASH_UBI_RWFS_SIZE ?= "6144"
FLASH_UBI_RWFS_TXT_SIZE ?= "6MiB"

SERIAL_CONSOLES ?= "115200;ttyS0"

BB_ALIGN ?= "524288"
ATF_ALIGN ?= "4096"
OPTEE_ALIGN ?= "4096"
UBOOT_ALIGN ?= "4096"
ALIGN_END ?= "4096"
PAD_ALIGN ?= "32"
SA_ALIGN ?= "524288"

SOC_FAMILY = "npcm8xx"
include conf/machine/include/soc-family.inc
MACHINEOVERRIDES .= ":npcm8xx"

require conf/machine/include/arm/armv8a/tune-cortexa35.inc

UBOOT_MKIMAGE:append:npcm8xx = " -E -B 8"

COMPATIBLE_MACHINE:npcm8xx = "npcm8xx"
TFA_PLATFORM = "npcm845x"

# Nuvoton prefers optee for BL32.
TFA_SPD = "opteed"

# Nuvoton prefers u-boot as BL33.
TFA_UBOOT = "1"

# Nuvoton prefers TFA default build is BL31.
TFA_BUILD_TARGET = "bl31"

OPTEEMACHINE ?= "nuvoton"

SECURED_IMAGE ?= "True"

TIP_IMAGE ?= "True"

SA_TIP_IMAGE ?= "False"
