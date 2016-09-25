Comenta el significado de las siguientes líneas de un fichero de configuración:


menuentry 'Ubuntu, con Linux 2.6.38-13-generic' --class ubuntu --class gnu-linux --class gnu
--class os {
	recordfail
	set gfxpayload=$linux_gfx_mode
	insmod part_msdos
	insmod ext2
	set root='(/dev/sda,msdos4)'
	search --no-floppy --fs-uuid --set=root e94a33b0-aad2-4a6d-8496-9b27e69c094c
	linux /boot/vmlinuz-2.6.38-13-generic root=UUID=e94a33b0-aad2-4a6d-8496-9b27e69c094c ro quiet splash
		initrd /boot/initrd.img-2.6.38-13-generic
}
¿Qué fichero modificaría para eliminar la opción quiet de todas las entradas linux?
	/etc/default/grub