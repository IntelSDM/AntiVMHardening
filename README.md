# AntiVMHardening
This is a POC of using the display device to detect VMs despite hardening attempts. VMs such as Hyper-V, VirtualBox and VMWare don't have proper pcie passthrough, they may have GPU passthrough but it will not emulate the host device, but rather use the VM's device.<br>
QEmu can defeat this with their PCIE passthrough which will pass through a physical GPU, requiring 2 GPUs to work. For basic anti analysis against RDC, General production VMs this works very well unless the attacker wants to implement their own PCIE emulation.
