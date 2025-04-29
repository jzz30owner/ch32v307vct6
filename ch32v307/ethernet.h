#include "ch32v307.h"


typedef struct {
  /**
 * @brief EMAC_MACCR - Ethernet Media Access Controller Configuration Register
 *
 * @details This 32-bit register configures the operating mode of the Ethernet MAC
 * on the CH32V307, located at address 0x40028000 (EMAC base). It controls key
 * parameters such as transmission/reception enable, speed (10/100 Mbps), duplex
 * mode, loopback, and checksum offloading. The EMAC clock must be enabled via
 * RCC_APB2ENR (bit 14), and relevant GPIO port clocks (e.g., GPIOA via bit 2)
 * must be enabled. GPIO pins (e.g., PA2 for ETH_MDIO, PB11 for ETH_RMII_TXD0)
 * must be configured as alternate functions via GPIOx_CRL/CRH, and EMAC pin
 * remapping (e.g., RMII mode) must be set via AFIO_PCFR1 (bit 23). An external
 * PHY must be initialized via MDIO for Ethernet communication.
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). Consult the CH32V307
 * datasheet and reference manual for detailed pin assignments and PHY requirements.
 *
 * Bit fields:
 * - Bits 31:26 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 25     : CSTF
 *   - Description: CRC stripping for Type frames
 *   - Values:
 *     - 0: CRC stripping disabled
 *     - 1: CRC stripping enabled for Type frames
 * - Bit 24     : WD
 *   - Description: Watchdog disable
 *   - Values:
 *     - 0: Watchdog enabled (frames > 2048 bytes dropped)
 *     - 1: Watchdog disabled (accepts oversized frames)
 * - Bit 23     : JD
 *   - Description: Jabber disable
 *   - Values:
 *     - 0: Jabber enabled (transmission stopped after 2048 bytes)
 *     - 1: Jabber disabled
 * - Bits 22:20 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bits 19:17 : IFG
 *   - Description: Interframe gap
 *   - Values:
 *     - 0x0: 96 bit times
 *     - 0x1: 88 bit times
 *     - 0x2: 80 bit times
 *     - 0x3: 72 bit times
 *     - 0x4: 64 bit times
 *     - 0x5: 56 bit times
 *     - 0x6: 48 bit times
 *     - 0x7: 40 bit times
 * - Bit 16     : CSD
 *   - Description: Carrier sense disable
 *   - Values:
 *     - 0: Carrier sense enabled
 *     - 1: Carrier sense disabled
 * - Bit 15     : FES
 *   - Description: Fast Ethernet speed
 *   - Values:
 *     - 0: 10 Mbps
 *     - 1: 100 Mbps
 * - Bit 14     : ROD
 *   - Description: Receive own disable
 *   - Values:
 *     - 0: Receive own frames in half-duplex
 *     - 1: Disable receiving own frames
 * - Bit 13     : LM
 *   - Description: Loopback mode
 *   - Values:
 *     - 0: Normal operation
 *     - 1: Loopback mode enabled
 * - Bit 12     : DM
 *   - Description: Duplex mode
 *   - Values:
 *     - 0: Half-duplex
 *     - 1: Full-duplex
 * - Bit 11     : IPCO
 *   - Description: IP checksum offload
 *   - Values:
 *     - 0: IP checksum offload disabled
 *     - 1: IP checksum offload enabled
 * - Bits 10:8  : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 7      : RD
 *   - Description: Retry disable
 *   - Values:
 *     - 0: Retry enabled in half-duplex
 *     - 1: Retry disabled
 * - Bits 6:5   : APCS
 *   - Description: Automatic pad/CRC stripping
 *   - Values:
 *     - 0x0: No stripping
 *     - 0x1: Strip pad/FCS for frames < 1536 bytes
 *     - 0x2: Strip pad/FCS for all frames
 *     - 0x3: Reserved
 * - Bit 4      : BL
 *   - Description: Back-off limit
 *   - Values:
 *     - 0: Standard back-off (IEEE 802.3)
 *     - 1: Reduced back-off
 * - Bit 3      : DC
 *   - Description: Deferral check
 *   - Values:
 *     - 0: Deferral check disabled
 *     - 1: Deferral check enabled
 * - Bit 2      : TE
 *   - Description: Transmitter enable
 *   - Values:
 *     - 0: Transmitter disabled
 *     - 1: Transmitter enabled
 * - Bit 1      : RE
 *   - Description: Receiver enable
 *   - Values:
 *     - 0: Receiver disabled
 *     - 1: Receiver enabled
 * - Bit 0      : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 */
  volatile uint32_t MACCR;
 
 /**
 * @brief EMAC_MACFFR - Ethernet MAC Frame Filter Register
 *
 * @details This 32-bit register configures frame filtering for the Ethernet MAC
 * on the CH32V307, located at address 0x40028004 (EMAC base + 0x04). It controls
 * which received frames are passed to the application, based on destination address
 * (unicast, multicast, broadcast), VLAN tags, or source address. Filtering modes
 * include promiscuous, hash-based, and perfect filtering. The EMAC clock must be
 * enabled via RCC_APB2ENR (bit 14), and relevant GPIO port clocks (e.g., GPIOA via
 * bit 2) must be enabled. GPIO pins (e.g., PA2 for ETH_MDIO, PB11 for ETH_RMII_TXD0)
 * must be configured as alternate functions via GPIOx_CRL/CRH, and EMAC pin
 * remapping (e.g., RMII mode) must be set via AFIO_PCFR1 (bit 23). The MAC receiver
 * must be enabled via EMAC_MACCR (bit 2) to process frames, and an external PHY
 * must be initialized.
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). Consult the CH32V307
 * datasheet and reference manual for detailed filtering options and PHY requirements.
 *
 * Bit fields:
 * - Bit 31     : RA
 *   - Description: Receive all
 *   - Values:
 *     - 0: Filter frames based on other settings
 *     - 1: Receive all frames (promiscuous mode, bypasses address filtering)
 * - Bit 30     : HPF
 *   - Description: Hash or perfect filter
 *   - Values:
 *     - 0: Perfect filtering for multicast/unicast
 *     - 1: Hash filtering for multicast/unicast
 * - Bit 29     : SAF
 *   - Description: Source address filter
 *   - Values:
 *     - 0: Source address filtering disabled
 *     - 1: Filter frames based on source address
 * - Bit 28     : SAIF
 *   - Description: Source address inverse filter
 *   - Values:
 *     - 0: Normal source address filtering (drop non-matching)
 *     - 1: Inverse filtering (drop matching source addresses)
 * - Bits 27:11 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 10     : VF
 *   - Description: VLAN filter
 *   - Values:
 *     - 0: VLAN filtering disabled
 *     - 1: Filter frames based on VLAN tag
 * - Bit 9      : HU
 *   - Description: Hash unicast
 *   - Values:
 *     - 0: Unicast filtering using perfect filter
 *     - 1: Unicast filtering using hash table
 * - Bit 8      : HM
 *   - Description: Hash multicast
 *   - Values:
 *     - 0: Multicast filtering using perfect filter
 *     - 1: Multicast filtering using hash table
 * - Bit 7      : DAIF
 *   - Description: Destination address inverse filter
 *   - Values:
 *     - 0: Normal destination address filtering
 *     - 1: Inverse filtering (drop matching destination addresses)
 * - Bit 6      : RAM
 *   - Description: Receive all multicast
 *   - Values:
 *     - 0: Filter multicast frames
 *     - 1: Pass all multicast frames
 * - Bit 5      : BF
 *   - Description: Broadcast frames
 *   - Values:
 *     - 0: Accept broadcast frames
 *     - 1: Drop broadcast frames
 * - Bit 4      : PCF
 *   - Description: Pass control frames
 *   - Values:
 *     - 0: Drop all control frames
 *     - 1: Pass control frames (e.g., PAUSE frames)
 * - Bit 3      : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 2      : PM
 *   - Description: Promiscuous mode
 *   - Values:
 *     - 0: Normal address filtering
 *     - 1: Promiscuous mode (pass all frames, similar to RA)
 * - Bit 1      : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 0      : PR
 *   - Description: Pass runt frames
 *   - Values:
 *     - 0: Drop frames shorter than 64 bytes
 *     - 1: Pass runt frames (if valid)
 */
  volatile uint32_t MACFFR;

 /**
 * @brief EMAC_MACHTHR - Ethernet MAC Hash Table High Register
 *
 * @details This 32-bit register stores the upper 32 bits (bits 63:32) of the 64-bit
 * hash table used for multicast and unicast address filtering on the CH32V307, located
 * at address 0x40028008 (EMAC base + 0x08). It works with EMAC_MACHTLR (bits 31:0)
 * to form the full hash table. When hash filtering is enabled via EMAC_MACFFR (bit 9
 * for unicast, bit 8 for multicast), the EMAC hashes a frame’s destination MAC address
 * to a 6-bit index (0–63), and the corresponding bit in the hash table determines if
 * the frame is accepted (1) or rejected (0). The EMAC clock must be enabled via
 * RCC_APB2ENR (bit 14), and relevant GPIO port clocks (e.g., GPIOA via bit 2) must
 * be enabled. GPIO pins (e.g., PA2 for ETH_MDIO, PB11 for ETH_RMII_TXD0) must be
 * configured as alternate functions via GPIOx_CRL/CRH, and EMAC pin remapping
 * (e.g., RMII mode) must be set via AFIO_PCFR1 (bit 23). The MAC receiver must be
 * enabled via EMAC_MACCR (bit 2), and an external PHY must be initialized.
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). The hash table is only
 * active when hash filtering is enabled in EMAC_MACFFR. Consult the CH32V307
 * datasheet and reference manual for hash table configuration and PHY requirements.
 *
 * Bit fields:
 * - Bits 31:0 : HTH
 *   - Description: Hash table high bits (bits 63:32 of the 64-bit hash table)
 *   - Values:
 *     - Each bit corresponds to a hash index (32 to 63)
 *     - 0: Reject frames with this hash index
 *     - 1: Accept frames with this hash index
 *     - Example: Bit 0 = hash index 32, Bit 31 = hash index 63
 */
  volatile uint32_t MACHTHR;

  /**
 * @brief EMAC_MACHTLR - Ethernet MAC Hash Table Low Register
 *
 * @details This 32-bit register stores the lower 32 bits (bits 31:0) of the 64-bit
 * hash table used for multicast and unicast address filtering on the CH32V307, located
 * at address 0x4002800C (EMAC base + 0x0C). It works with EMAC_MACHTHR (bits 63:32)
 * to form the full hash table. When hash filtering is enabled via EMAC_MACFFR (bit 9
 * for unicast, bit 8 for multicast), the EMAC hashes a frame’s destination MAC address
 * to a 6-bit index (0–63), and the corresponding bit in the hash table determines if
 * the frame is accepted (1) or rejected (0). The EMAC clock must be enabled via
 * RCC_APB2ENR (bit 14), and relevant GPIO port clocks (e.g., GPIOA via bit 2) must
 * be enabled. GPIO pins (e.g., PA2 for ETH_MDIO, PB11 for ETH_RMII_TXD0) must be
 * configured as alternate functions via GPIOx_CRL/CRH, and EMAC pin remapping
 * (e.g., RMII mode) must be set via AFIO_PCFR1 (bit 23). The MAC receiver must be
 * enabled via EMAC_MACCR (bit 2), and an external PHY must be initialized.
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). The hash table is only
 * active when hash filtering is enabled in EMAC_MACFFR. Consult the CH32V307
 * datasheet and reference manual for hash table configuration and PHY requirements.
 *
 * Bit fields:
 * - Bits 31:0 : HTL
 *   - Description: Hash table low bits (bits 31:0 of the 64-bit hash table)
 *   - Values:
 *     - Each bit corresponds to a hash index (0 to 31)
 *     - 0: Reject frames with this hash index
 *     - 1: Accept frames with this hash index
 *     - Example: Bit 0 = hash index 0, Bit 31 = hash index 31
 */
  volatile uint32_t MACHTLR;

 /**
 * @brief EMAC_MACMIIAR - Ethernet MAC MII Address Register
 *
 * @details This 32-bit register configures the Management Data Input/Output (MDIO)
 * interface for read/write operations with an external PHY on the CH32V307, located
 * at address 0x40028010 (EMAC base + 0x10). It specifies the PHY address (0–31),
 * the PHY register address (0–31), the operation type (read or write), and the MDIO
 * clock divider. The EMAC uses MDIO (via PA2) and MDC (via PA1) to communicate with
 * the PHY. The EMAC clock must be enabled via RCC_APB2ENR (bit 14), and relevant
 * GPIO port clocks (e.g., GPIOA via bit 2) must be enabled. MDIO (PA2) and MDC (PA1)
 * pins must be configured as alternate function push-pull outputs via GPIOx_CRL/CRH,
 * and EMAC pin remapping (e.g., RMII mode) must be set via AFIO_PCFR1 (bit 23).
 * For write operations, data is written to EMAC_MACMIIDR before setting the busy bit.
 * For read operations, data is read from EMAC_MACMIIDR after the busy bit clears.
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). The MDIO clock frequency
 * must comply with IEEE 802.3 (typically ≤ 2.5 MHz). Consult the CH32V307 datasheet
 * and reference manual for PHY communication details and pin assignments.
 *
 * Bit fields:
 * - Bits 31:13 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 12     : MW
 *   - Description: MII write
 *   - Values:
 *     - 0: Read operation
 *     - 1: Write operation
 * - Bit 11     : MB
 *   - Description: MII busy
 *   - Values:
 *     - 0: MDIO interface idle
 *     - 1: MDIO operation in progress (set by software, cleared by hardware)
 * - Bits 10:6  : PA
 *   - Description: PHY address
 *   - Values:
 *     - 0x00–0x1F: PHY address (0 to 31)
 *     - Example: 0x01 for PHY at address 1
 * - Bits 5:3   : CR
 *   - Description: Clock range (MDIO clock divider)
 *   - Values:
 *     - 0x0: HCLK/4 (e.g., 36 MHz HCLK → 9 MHz MDC)
 *     - 0x1: HCLK/6 (e.g., 36 MHz HCLK → 6 MHz MDC)
 *     - 0x2: HCLK/8 (e.g., 36 MHz HCLK → 4.5 MHz MDC)
 *     - 0x3: HCLK/10 (e.g., 36 MHz HCLK → 3.6 MHz MDC)
 *     - 0x4: HCLK/12 (e.g., 36 MHz HCLK → 3 MHz MDC)
 *     - 0x5: HCLK/14 (e.g., 36 MHz HCLK → 2.57 MHz MDC)
 *     - 0x6: HCLK/16 (e.g., 36 MHz HCLK → 2.25 MHz MDC)
 *     - 0x7: HCLK/18 (e.g., 36 MHz HCLK → 2 MHz MDC)
 * - Bits 2:0   : RGA
 *   - Description: Register address
 *   - Values:
 *     - 0x00–0x1F: PHY register address (0 to 31)
 *     - Example: 0x00 for PHY control register
 */
  volatile uint32_t MACMIIAR;

 /**
 * @brief EMAC_MACMIIDR - Ethernet MAC MII Data Register
 *
 * @details This 32-bit register holds the 16-bit data for Management Data Input/Output
 * (MDIO) read/write operations with an external PHY on the CH32V307, located at address
 * 0x40028014 (EMAC base + 0x14). For write operations, software writes the 16-bit data
 * to this register before triggering the operation via EMAC_MAC—MIIAR (setting MW=1, MB=1).
 * For read operations, the EMAC writes the 16-bit data from the PHY register to this
 * register after the operation completes (when EMAC_MACMIIAR's MB bit clears). The EMAC
 * clock must be enabled via RCC_APB2ENR (bit 14), and relevant GPIO port clocks (e.g.,
 * GPIOA via bit 2) must be enabled. MDIO (PA2) and MDC (PA1) pins must be configured
 * as alternate function push-pull outputs via GPIOx_CRL/CRH, and EMAC pin remapping
 * (e.g., RMII mode) must be set via AFIO_PCFR1 (bit 23). The EMAC_MACMIIAR register
 * must be configured with the PHY address, register address, and operation type before
 * accessing this register.
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). Only the lower 16 bits
 * of this register are used for MDIO data; the upper 16 bits are reserved. Consult
 * the CH32V307 datasheet and reference manual for PHY communication details and
 * pin assignments.
 *
 * Bit fields:
 * - Bits 31:16 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bits 15:0  : MD
 *   - Description: MII data
 *   - Values:
 *     - 0x0000–0xFFFF: 16-bit data to write to or read from the PHY register
 *     - Example: For write, set to PHY register value; for read, contains PHY register value
 */
  volatile uint32_t MACMIIDR;

  /**
 * @brief EMAC_MACFCR - Ethernet MAC Flow Control Register
 *
 * @details This 32-bit register configures Ethernet flow control mechanisms on the
 * CH32V307, located at address 0x40028018 (EMAC base + 0x18). It enables/disables
 * flow control for full-duplex (PAUSE frames) and half-duplex (backpressure) modes,
 * sets the receive FIFO threshold for sending PAUSE frames, and specifies the PAUSE
 * time. The EMAC clock must be enabled via RCC_APB2ENR (bit 14), and relevant GPIO
 * port clocks (e.g., GPIOA via bit 2) must be enabled. EMAC pins (e.g., PA2 for
 * ETH_MDIO, PA1 for ETH_MDC) must be configured as alternate functions via
 * GPIOx_CRL/CRH, and pin remapping (e.g., RMII mode) must be set via AFIO_PCFR1
 * (bit 23). The PHY must be initialized via EMAC_MACMIIAR/EMAC_MACMIIDR to support
 * flow control, and EMAC_MACCR must configure the appropriate duplex mode.
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). Flow control is only
 * effective if the PHY and link partner support it. Consult the CH32V307 datasheet
 * and reference manual for flow control details and pin assignments.
 *
 * Bit fields:
 * - Bits 31:16 : PT
 *   - Description: PAUSE time
 *   - Values:
 *     - 0x0000–0xFFFF: PAUSE time in slot times (512 bit times per slot)
 *     - Example: 0x0064 = 100 slot times
 * - Bits 15:8  : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 7      : ZQPD
 *   - Description: Zero-quanta PAUSE disable
 *   - Values:
 *     - 0: Enable zero-quanta PAUSE frames
 *     - 1: Disable zero-quanta PAUSE frames
 * - Bits 6:5   : RFT
 *   - Description: Receive FIFO threshold
 *   - Values:
 *     - 0x0: 2 KB full
 *     - 0x1: 3 KB full
 *     - 0x2: 4 KB full
 *     - 0x3: 5 KB full
 * - Bit 4      : UPFD
 *   - Description: Unicast PAUSE frame detect
 *   - Values:
 *     - 0: Detect PAUSE frames with multicast address only
 *     - 1: Detect PAUSE frames with unicast or multicast address
 * - Bit 3      : PLT
 *   - Description: PAUSE low threshold
 *   - Values:
 *     - 0: PAUSE time minus 4 slot times
 *     - 1: PAUSE time minus 28 slot times
 * - Bit 2      : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 1      : BPA
 *   - Description: Backpressure activate
 *   - Values:
 *     - 0: Disable backpressure in half-duplex
 *     - 1: Enable backpressure (force collisions during congestion)
 * - Bit 0      : FCE
 *   - Description: Flow control enable
 *   - Values:
 *     - 0: Disable flow control (PAUSE frames)
 *     - 1: Enable flow control (send/process PAUSE frames in full-duplex)
 */
  volatile uint32_t MACFCR;

  /**
 * @brief EMAC_MACVLANTR - Ethernet MAC VLAN Tag Register
 *
 * @details This 32-bit register configures VLAN tag filtering for received Ethernet
 * frames on the CH32V307, located at address 0x4002801C (EMAC base + 0x1C). It
 * specifies the 16-bit VLAN Identifier (VID) for perfect filtering or hash-based
 * filtering and controls whether 12-bit or 16-bit VID comparison is used. VLAN
 * filtering must be enabled via EMAC_MACFFR (bit 10, VF) for this register to take
 * effect. The EMAC clock must be enabled via RCC_APB2ENR (bit 14), and relevant
 * GPIO port clocks (e.g., GPIOA via bit 2) must be enabled. EMAC pins (e.g., PA2
 * for ETH_MDIO, PA1 for ETH_MDC) must be configured as alternate functions via
 * GPIOx_CRL/CRH, and pin remapping (e.g., RMII mode) must be set via AFIO_PCFR1
 * (bit 23). The PHY must be initialized via EMAC_MACMIIAR/EMAC_MACMIIDR to support
 * VLAN-tagged frames, if required, and the receiver must be enabled via EMAC_MACCR
 * (bit 2).
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). VLAN filtering requires
 * the link partner to send VLAN-tagged frames per IEEE 802.1Q. Consult the CH32V307
 * datasheet and reference manual for VLAN filtering details and pin assignments.
 *
 * Bit fields:
 * - Bits 31:18 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 17     : VTHM
 *   - Description: VLAN tag hash match
 *   - Values:
 *     - 0: Perfect filtering (exact VID match)
 *     - 1: Hash-based filtering (VID hashed to a single bit)
 * - Bit 16     : EVR
 *   - Description: Enable VLAN 12-bit comparison
 *   - Values:
 *     - 0: Compare full 16-bit VID
 *     - 1: Compare lower 12 bits of VID
 * - Bits 15:0  : VL
 *   - Description: VLAN tag identifier
 *   - Values:
 *     - 0x0000–0xFFFF: 16-bit VLAN ID for filtering
 *     - Example: 0x0001 for VLAN ID 1
 */
  volatile uint32_t MACVLANTR;

  uint32_t RESERVED0[2];

  /**
 * @brief EMAC_MACRWUFFR - Ethernet MAC Remote Wake-Up Frame Filter Register
 *
 * @details This 32-bit register configures the remote wake-up frame filter for
 * Wake-on-LAN (WoL) on the CH32V307, located at address 0x40028028 (EMAC base + 0x28).
 * It is a multi-word register used to define up to four wake-up frame filters, each
 * specifying parameters such as multicast address checks, byte offsets, byte masks,
 * and CRC values for detecting wake-up frames (e.g., Magic Packets). Wake-up frame
 * detection must be enabled via EMAC_MACPMTCSR (bit 2, WFE) for this register to
 * take effect. The EMAC clock must be enabled via RCC_APB2ENR (bit 14), and relevant
 * GPIO port clocks (e.g., GPIOA via bit 2) must be enabled. EMAC pins (e.g., PA2 for
 * ETH_MDIO, PA1 for ETH_MDC) must be configured as alternate functions via
 * GPIOx_CRL/CRH, and pin remapping (e.g., RMII mode) must be set via AFIO_PCFR1
 * (bit 23). The PHY must be initialized via EMAC_MACMIIAR/EMAC_MACMIIDR to support
 * WoL, if required, and the receiver must be enabled via EMAC_MACCR (bit 2).
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). The register is written
 * multiple times to configure each filter's command, offset, mask, and CRC fields.
 * A typical Magic Packet contains the MAC address repeated 16 times after a sync
 * pattern (0xFFFFFFFFFFFF). Consult the CH32V307 datasheet and reference manual for
 * wake-up filter configuration details and pin assignments.
 *
 * Bit fields (per filter write, repeated for each filter):
 * - Bits 31:16 : Filter CRC
 *   - Description: 16-bit CRC of the wake-up frame pattern (when writing CRC data)
 *   - Values:
 *     - 0x0000–0xFFFF: CRC value for the pattern
 *     - Example: CRC of the Magic Packet pattern
 * - Bits 15:8  : Filter Offset
 *   - Description: Byte offset in the frame for pattern matching (when writing offset data)
 *   - Values:
 *     - 0x00–0xFF: Byte offset from frame start
 *     - Example: 12 for start of destination address
 * - Bits 7:4   : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 3      : Filter Multicast
 *   - Description: Enable multicast address check (when writing command data)
 *   - Values:
 *     - 0: Filter unicast or multicast frames
 *     - 1: Filter only multicast frames
 * - Bits 2:1   : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 0      : Filter Enable
 *   - Description: Enable the filter (when writing command data)
 *   - Values:
 *     - 0: Disable the filter
 *     - 1: Enable the filter
 * - Bits 31:0  : Filter Mask
 *   - Description: 32-bit byte mask for selective pattern matching (when writing mask data)
 *   - Values:
 *     - 0x00000000–0xFFFFFFFF: Mask bits (1 = compare, 0 = ignore)
 *     - Example: 0xFFFFFFFF for full pattern match
 */
  volatile uint32_t MACRWUFFR;

  /**
 * @brief EMAC_MACPMTCSR - Ethernet MAC Power Management Control and Status Register
 *
 * @details This 32-bit register controls and monitors power management features for
 * Wake-on-LAN (WoL) on the CH32V307, located at address 0x4002802C (EMAC base + 0x2C).
 * It enables/disables detection of Magic Packets and wake-up frames, controls power-down
 * modes, and reports wake-up events through status flags. Magic Packet detection
 * identifies frames with a sync pattern (0xFFFFFFFFFFFF) followed by 16 repetitions
 * of the MAC address. Wake-up frame detection uses filters configured in EMAC_MACRWUFFR.
 * The EMAC clock must be enabled via RCC_APB2ENR (bit 14), and relevant GPIO port
 * clocks (e.g., GPIOA via bit 2) must be enabled. EMAC pins (e.g., PA2 for ETH_MDIO,
 * PA1 for ETH_MDC) must be configured as alternate functions via GPIOx_CRL/CRH, and
 * pin remapping (e.g., RMII mode) must be set via AFIO_PCFR1 (bit 23). The PHY must
 * be initialized via EMAC_MACMIIAR/EMAC_MACMIIDR to support WoL, and the receiver
 * must be enabled via EMAC_MACCR (bit 2).
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). WoL requires the PHY to
 * remain powered in low-power modes and may involve EXTI interrupts for wake-up
 * events. Consult the CH32V307 datasheet and reference manual for power management
 * and WoL configuration details.
 *
 * Bit fields:
 * - Bits 31:10 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 9      : WFR
 *   - Description: Wake-up frame received
 *   - Values:
 *     - 0: No wake-up frame received
 *     - 1: Wake-up frame detected (write 1 to clear)
 * - Bit 8      : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 7      : GU
 *   - Description: Global unicast
 *   - Values:
 *     - 0: Only multicast wake-up frames detected
 *     - 1: Unicast wake-up frames also detected
 * - Bit 6      : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 5      : MPR
 *   - Description: Magic Packet received
 *   - Values:
 *     - 0: No Magic Packet received
 *     - 1: Magic Packet detected (write 1 to clear)
 * - Bits 4:3   : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 2      : WFE
 *   - Description: Wake-up frame enable
 *   - Values:
 *     - 0: Disable wake-up frame detection
 *     - 1: Enable wake-up frame detection (uses EMAC_MACRWUFFR filters)
 * - Bit 1      : MPE
 *   - Description: Magic Packet enable
 *   - Values:
 *     - 0: Disable Magic Packet detection
 *     - 1: Enable Magic Packet detection
 * - Bit 0      : PD
 *   - Description: Power down
 *   - Values:
 *     - 0: Normal operation
 *     - 1: Power-down mode (WoL detection active)
 */
  volatile uint32_t MACPMTCSR;

  uint32_t RESERVED1;

  /**
 * @brief EMAC_MACDBGR - Ethernet MAC Debug Register
 *
 * @details This 32-bit read-only register provides status information about the
 * Ethernet MAC's internal state on the CH32V307, located at address 0x40028034
 * (EMAC base + 0x34). It reports the state of the transmitter and receiver state
 * machines, FIFO fill levels, and flow control conditions, aiding in debugging issues
 * with frame transmission, reception, or flow control. The EMAC clock must be enabled
 * via RCC_APB2ENR (bit 14), and relevant GPIO port clocks (e.g., GPIOA via bit 2)
 * must be enabled. EMAC pins (e.g., PA2 for ETH_MDIO, PA1 for ETH_MDC) must be
 * configured as alternate functions via GPIOx_CRL/CRH, and pin remapping (e.g., RMII
 * mode) must be set via AFIO_PCFR1 (bit 23). The PHY must be initialized via
 * EMAC_MACMIIAR/EMAC_MACMIIDR, and the transmitter/receiver must be enabled via
 * EMAC_MACCR (bits 2 and 3).
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). This register is read-only
 * and used for diagnostic purposes only. Consult the CH32V307 datasheet and reference
 * manual for debugging details and pin assignments.
 *
 * Bit fields:
 * - Bits 31:26 : Reserved
 *   - Description: Reserved, read as 0
 *   - Values: N/A
 * - Bit 25     : TFF
 *   - Description: Transmit FIFO full
 *   - Values:
 *     - 0: Transmit FIFO not full
 *     - 1: Transmit FIFO full
 * - Bit 24     : TFNE
 *   - Description: Transmit FIFO not empty
 *   - Values:
 *     - 0: Transmit FIFO empty
 *     - 1: Transmit FIFO not empty
 * - Bits 23:22 : TFWA
 *   - Description: Transmit FIFO write active
 *   - Values:
 *     - 0: No write operation
 *     - 1: Write operation active
 * - Bits 21:19 : TFRS
 *   - Description: Transmit frame state
 *   - Values:
 *     - 0x0: Idle
 *     - 0x1: Waiting for status
 *     - 0x2: Transmitting frame
 *     - 0x3: Writing status
 *     - 0x4–0x7: Reserved
 * - Bit 18     : MTP
 *   - Description: MAC transmitter paused
 *   - Values:
 *     - 0: Transmitter not paused
 *     - 1: Transmitter paused (e.g., due to PAUSE frame)
 * - Bit 17     : MTFCS
 *   - Description: MAC transmit FCS generation
 *   - Values:
 *     - 0: FCS generation inactive
 *     - 1: FCS generation active
 * - Bit 16     : MMTE
 *   - Description: MAC MII transmit engine
 *   - Values:
 *     - 0: MII transmit engine inactive
 *     - 1: MII transmit engine active
 * - Bits 15:10 : Reserved
 *   - Description: Reserved, read as 0
 *   - Values: N/A
 * - Bit 9      : RFF
 *   - Description: Receive FIFO full
 *   - Values:
 *     - 0: Receive FIFO not full
 *     - 1: Receive FIFO full
 * - Bit 8      : RFNE
 *   - Description: Receive FIFO not empty
 *   - Values:
 *     - 0: Receive FIFO empty
 *     - 1: Receive FIFO not empty
 * - Bits 7:6   : RFRS
 *   - Description: Receive frame state
 *   - Values:
 *     - 0x0: Idle
 *     - 0x1: Receiving frame
 *     - 0x2: Writing frame to FIFO
 *     - 0x3: Flushing frame
 * - Bits 5:4   : RFRA
 *   - Description: Receive FIFO read active
 *   - Values:
 *     - 0: No read operation
 *     - 1: Read operation active
 * - Bits 3:2   : Reserved
 *   - Description: Reserved, read as 0
 *   - Values: N/A
 * - Bit 1      : MSRE
 *   - Description: MAC small receive engine
 *   - Values:
 *     - 0: Small receive engine inactive
 *     - 1: Small receive engine active
 * - Bit 0      : MMRE
 *   - Description: MAC MII receive engine
 *   - Values:
 *     - 0: MII receive engine inactive
 *     - 1: MII receive engine active
 */
  volatile uint32_t MACDBGR;

  /**
 * @brief EMAC_MACSR - Ethernet MAC Status Register
 *
 * @details This 32-bit read-write register reports the status of Ethernet MAC events
 * on the CH32V307, located at address 0x40028038 (EMAC base + 0x38). It includes
 * flags for power management events (e.g., Wake-on-LAN via Magic Packets or wake-up
 * frames), timestamp triggers (for IEEE 1588 PTP), and MII interface errors (e.g.,
 * PHY link status changes). Some bits are cleared by writing 1, and interrupts can
 * be masked via EMAC_MACIMR. The EMAC clock must be enabled via RCC_APB2ENR (bit 14),
 * and relevant GPIO port clocks (e.g., GPIOA via bit 2) must be enabled. EMAC pins
 * (e.g., PA2 for ETH_MDIO, PA1 for ETH_MDC) must be configured as alternate functions
 * via GPIOx_CRL/CRH, and pin remapping (e.g., RMII mode) must be set via AFIO_PCFR1
 * (bit 23). The PHY must be initialized via EMAC_MACMIIAR/EMAC_MACMIIDR, and the
 * receiver must be enabled via EMAC_MACCR (bit 2).
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). Interrupts may require
 * NVIC or EXTI configuration for handling. Consult the CH32V307 datasheet and
 * reference manual for status and interrupt handling details.
 *
 * Bit fields:
 * - Bits 31:11 : Reserved
 *   - Description: Reserved, read as 0
 *   - Values: N/A
 * - Bit 10     : TSTS
 *   - Description: Timestamp trigger status
 *   - Values:
 *     - 0: No timestamp trigger event
 *     - 1: Timestamp trigger event occurred (write 1 to clear)
 * - Bit 9      : PMTS
 *   - Description: Power management trigger status
 *   - Values:
 *     - 0: No power management event
 *     - 1: Power management event (e.g., Magic Packet or wake-up frame) detected (write 1 to clear)
 * - Bits 8:7   : Reserved
 *   - Description: Reserved, read as 0
 *   - Values: N/A
 * - Bit 6      : MMCS
 *   - Description: MII status
 *   - Values:
 *     - 0: No MII status change
 *     - 1: MII status changed (e.g., PHY link status) (write 1 to clear)
 * - Bit 5      : MMCRS
 *   - Description: MII receive status
 *   - Values:
 *     - 0: No MII receive error
 *     - 1: MII receive error detected (write 1 to clear)
 * - Bit 4      : MMCTS
 *   - Description: MII transmit status
 *   - Values:
 *     - 0: No MII transmit error
 *     - 1: MII transmit error detected (write 1 to clear)
 * - Bits 3:0   : Reserved
 *   - Description: Reserved, read as 0
 *   - Values: N/A
 */ 
  volatile uint32_t MACSR;

  /**
 * @brief EMAC_MACIMR - Ethernet MAC Interrupt Mask Register
 *
 * @details This 32-bit read-write register controls the masking of interrupts for
 * Ethernet MAC events on the CH32V307, located at address 0x4002803C (EMAC base + 0x3C).
 * It enables or disables interrupts reported in EMAC_MACSR by setting bits to 1 (mask,
 * disable interrupt) or 0 (unmask, enable interrupt). Events include power management
 * triggers (e.g., Wake-on-LAN via Magic Packets or wake-up frames), timestamp triggers
 * (for IEEE 1588 PTP), and MII interface errors (e.g., PHY link status changes). The
 * EMAC clock must be enabled via RCC_APB2ENR (bit 14), and relevant GPIO port clocks
 * (e.g., GPIOA via bit 2) must be enabled. EMAC pins (e.g., PA2 for ETH_MDIO, PA1 for
 * ETH_MDC) must be configured as alternate functions via GPIOx_CRL/CRH, and pin
 * remapping (e.g., RMII mode) must be set via AFIO_PCFR1 (bit 23). The PHY must be
 * initialized via EMAC_MACMIIAR/EMAC_MACMIIDR, and the receiver must be enabled via
 * EMAC_MACCR (bit 2).
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). Interrupts may require
 * NVIC or EXTI configuration for handling. Consult the CH32V307 datasheet and
 * reference manual for interrupt masking and handling details.
 *
 * Bit fields:
 * - Bits 31:11 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 10     : TSTM
 *   - Description: Timestamp trigger interrupt mask
 *   - Values:
 *     - 0: Timestamp trigger interrupt enabled
 *     - 1: Timestamp trigger interrupt disabled
 * - Bit 9      : PMTM
 *   - Description: Power management trigger interrupt mask
 *   - Values:
 *     - 0: Power management interrupt enabled
 *     - 1: Power management interrupt disabled
 * - Bits 8:7   : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 6      : MMCM
 *   - Description: MII status interrupt mask
 *   - Values:
 *     - 0: MII status interrupt enabled
 *     - 1: MII status interrupt disabled
 * - Bit 5      : MMCRM
 *   - Description: MII receive status interrupt mask
 *   - Values:
 *     - 0: MII receive status interrupt enabled
 *     - 1: MII receive status interrupt disabled
 * - Bit 4      : MMCTM
 *   - Description: MII transmit status interrupt mask
 *   - Values:
 *     - 0: MII transmit status interrupt enabled
 *     - 1: MII transmit status interrupt disabled
 * - Bits 3:0   : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 */
  volatile uint32_t MACIMR;

  /**
 * @brief EMAC_MACA0HR - Ethernet MAC Address 0 High Register
 *
 * @details This 32-bit read-write register stores the upper 16 bits (bits 47:32) of
 * the primary 48-bit MAC address (MAC Address 0) on the CH32V307, located at address
 * 0x40028040 (EMAC base + 0x40). It is used for frame filtering and as the source
 * address in transmitted frames, working with EMAC_MACA0LR (lower 32 bits). It also
 * includes control bits for enabling the address and applying byte masks for filtering.
 * The EMAC clock must be enabled via RCC_APB2ENR (bit 14), and relevant GPIO port
 * clocks (e.g., GPIOA via bit 2) must be enabled. EMAC pins (e.g., PA2 for ETH_MDIO,
 * PA1 for ETH_MDC) must be configured as alternate functions via GPIOx_CRL/CRH, and
 * pin remapping (e.g., RMII mode) must be set via AFIO_PCFR1 (bit 23). The PHY must
 * be initialized via EMAC_MACMIIAR/EMAC_MACMIIDR, and the receiver must be enabled
 * via EMAC_MACCR (bit 2). Frame filtering must be configured in EMAC_MACFFR for the
 * MAC address to be used.
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). The MAC address must be
 * unique on the network to avoid conflicts. Consult the CH32V307 datasheet and
 * reference manual for MAC address configuration details.
 *
 * Bit fields:
 * - Bit 31     : AE
 *   - Description: Address enable
 *   - Values:
 *     - 0: MAC address 0 disabled
 *     - 1: MAC address 0 enabled for filtering
 * - Bits 30:24 : MB
 *   - Description: Mask byte control
 *   - Values:
 *     - Bit 24: Mask byte 0 (1 = ignore, 0 = compare)
 *     - Bit 25: Mask byte 1
 *     - Bit 26: Mask byte 2
 *     - Bit 27: Mask byte 3
 *     - Bit 28: Mask byte 4
 *     - Bit 29: Mask byte 5
 *     - Bit 30: Reserved (set to 0)
 * - Bits 23:16 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bits 15:0  : MACA0H
 *   - Description: MAC address 0 high (bits 47:32)
 *   - Values:
 *     - 0x0000–0xFFFF: Upper 16 bits of the 48-bit MAC address
 *     - Example: 0x001A for MAC address 00:1A:2B:3C:4D:5E
 */
  volatile uint32_t MACA0HR;

  /**
 * @brief EMAC_MACA0LR - Ethernet MAC Address 0 Low Register
 *
 * @details This 32-bit read-write register stores the lower 32 bits (bits 31:0) of
 * the primary 48-bit MAC address (MAC Address 0) on the CH32V307, located at address
 * 0x40028044 (EMAC base + 0x44). It is used for frame filtering and as the source
 * address in transmitted frames, working with EMAC_MACA0HR (upper 16 bits and control
 * bits). The EMAC clock must be enabled via RCC_APB2ENR (bit 14), and relevant GPIO
 * port clocks (e.g., GPIOA via bit 2) must be enabled. EMAC pins (e.g., PA2 for
 * ETH_MDIO, PA1 for ETH_MDC) must be configured as alternate functions via
 * GPIOx_CRL/CRH, and pin remapping (e.g., RMII mode) must be set via AFIO_PCFR1
 * (bit 23). The PHY must be initialized via EMAC_MACMIIAR/EMAC_MACMIIDR, and the
 * receiver must be enabled via EMAC_MACCR (bit 2). Frame filtering must be configured
 * in EMAC_MACFFR, and the address must be enabled in EMAC_MACA0HR (bit 31).
 *
 * @note The CH32V307 supports 10/100 Mbps Ethernet with MII or RMII interfaces.
 * Only GPIO ports PA, PB, PC, PD, and PE are available for EMAC signals. Ensure
 * the correct pin remapping (e.g., RMII vs. MII) is set in AFIO_PCFR1, and verify
 * pin availability based on the package (e.g., LQFP100). The MAC address must be
 * unique on the network to avoid conflicts. Consult the CH32V307 datasheet and
 * reference manual for MAC address configuration details.
 *
 * Bit fields:
 * - Bits 31:0  : MACA0L
 *   - Description: MAC address 0 low (bits 31:0)
 *   - Values:
 *     - 0x00000000–0xFFFFFFFF: Lower 32 bits of the 48-bit MAC address
 *     - Example: 0x2B3C4D5E for MAC address 00:1A:2B:3C:4D:5E
 */  
  volatile uint32_t MACA0LR;
} EMAC_TypeDef;


#define ETH            ((EMAC_TypeDef *) ETH_BASE)



