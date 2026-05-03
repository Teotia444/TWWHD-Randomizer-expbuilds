.org 0x025b0330 ; In dScnPly_Execute 0x803FE87C
  bl give_archipelago_item

; Every frame, check if the Archipelago client has set an item ID to give to the player.
; The byte is cleared after the item is given. We put this function in `dScnPly_Execute`, which is run every frame.
.org @NextFreeSpace
.global give_archipelago_item
give_archipelago_item:
  stwu    sp, -0x10 (sp)
  mflr    r0
  stw     r0, 0x14 (sp)
  stw     r31, 0xC (sp)
  
  ; Store value of r3 in r31
  mr      r31, r3
  
  ; Load the address of give_archipelago_item_byte into r4
  lis     r4, give_archipelago_item_byte@ha
  addi    r4, r4, give_archipelago_item_byte@l
  
  ; Load the item ID into r3
  lbz     r3, 0 (r4)
  
  ; If item ID is 0xFF, there's no item to give
  cmpwi   r3, 0xFF
  beq     give_archipelago_item_end
  
  ; Else, clear the byte to 0xFF before giving the item
  li      r5, 0xFF
  stb     r5, 0 (r4)
  
  ; Branch to execItemGet to give the item
  bl      execItemGet
  
  give_archipelago_item_end:
  ; Restore the value of r3
  mr      r3, r31
  
  bl fopOvlpM_IsPeek  ; this is the line we overwrote on 0x025b0330
  
  lwz     r31, 0xC (sp)
  lwz     r0, 0x14 (sp)
  mtlr    r0
  addi    sp, sp, 0x10




  blr

.global give_archipelago_item_byte
give_archipelago_item_byte:
  .byte 0xFF
.align 2 ; Align to the next 4 bytes

; Allocate 0x40 bytes in memory for the player's slot name
.global archipelago_slot_name
archipelago_slot_name:
  .space 0x40
.align 2 ; Align to the next 4 bytes


; Allocate 49 shorts in memory for the charts mapping
.global archipelago_charts_mapping
archipelago_charts_mapping:
  .space 0x62
.align 2 ; Align to the next 4 bytes