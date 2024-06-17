# Debugger USB Access Permissions
By default, OpenOCD will require sudo permissions to talk to the debugger. Installing udev rules will get around this and
allow VSCode to start a debug session from userland.

1. Copy the `openocd/99-openocd-pico-debug.rules` file to `/etc/udev/rules.d/`
2. Add the current user to the `plugdev` group by running: `sudo usermod -a -G plugdev $USER`
3. Reload the group assignment without logging out: `su - $USER`
4. Reload the udev rules by running `sudo udevadm control --reload-rules` and then `sudo udevadm trigger`.

# Example VSCode Launch.json Entry
This expects that `arm-none-eabi-gdb` and `openocd` are installed and available in the system PATH.
```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Pico-Debug Attach",
      "cwd": "${workspaceRoot}",
      "executable": "${command:cmake.launchTargetPath}",
      "request": "attach",
      "type": "cortex-debug",
      "servertype": "openocd",
      "gdbPath": "arm-none-eabi-gdb",
      "device": "RP2040",
      "configFiles": [
        "interface/cmsis-dap.cfg",
        "${workspaceRoot}/lib/pico-debug/openocd/rp2040-core0.cfg"
      ],
      "openOCDLaunchCommands": [
        "transport select swd",
        "adapter speed 4000"
      ],
      "svdFile": "${workspaceRoot}lib/pico-sdk/src/rp2040/hardware_regs/rp2040.svd",
      "searchDir": [
        "/usr/share/openocd/scripts"
      ]
    }
  ]
}
```