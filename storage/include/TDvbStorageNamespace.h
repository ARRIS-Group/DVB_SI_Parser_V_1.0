// DVB_SI for Reference Design Kit (RDK)
//
// Copyright 2015 ARRIS Enterprises
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA.

#ifndef TDVBSTORAGENAMESPACE_H
#define TDVBSTORAGENAMESPACE_H

#include <stdint.h>
#include <string>
#include <vector>

namespace TDvbStorageNamespace
{
  enum TModulationMode {
    MODULATION_MODE_UNKNOWN=0,
    MODULATION_MODE_QPSK,
    MODULATION_MODE_BPSK,
    MODULATION_MODE_OQPSK,
    MODULATION_MODE_VSB8,
    MODULATION_MODE_VSB16,
    MODULATION_MODE_QAM16,
    MODULATION_MODE_QAM32,
    MODULATION_MODE_QAM64,
    MODULATION_MODE_QAM80,
    MODULATION_MODE_QAM96,
    MODULATION_MODE_QAM112,
    MODULATION_MODE_QAM128,
    MODULATION_MODE_QAM160,
    MODULATION_MODE_QAM192,
    MODULATION_MODE_QAM224,
    MODULATION_MODE_QAM256,
    MODULATION_MODE_QAM320,
    MODULATION_MODE_QAM384,
    MODULATION_MODE_QAM448,
    MODULATION_MODE_QAM512,
    MODULATION_MODE_QAM640,
    MODULATION_MODE_QAM768,
    MODULATION_MODE_QAM896,
    MODULATION_MODE_QAM1024,
    MODULATION_MODE_QAM_NTSC // for analog mode
  };

  // TFileStatus - Db open return codes
  enum TFileStatus {
    FILE_STATUS_ERROR,
    FILE_STATUS_INVALID_NAME,
    FILE_STATUS_OPENED,
    FILE_STATUS_CREATED
  };

  /**
  * TransportStream structure. Used to represent a Transport Stream from storage collections.
  */
  typedef struct TStorageTransportStream {
    TStorageTransportStream(uint32_t fr, TModulationMode mod,
      uint32_t sym, uint16_t net, uint16_t ts)
      : Frequency(fr),
        Modulation(mod),
        SymbolRate (sym),
        NetworkId(net),
        TransportStreamId(ts)
    {
      // Empty
    }
    uint32_t Frequency;
    TModulationMode Modulation;
    uint32_t SymbolRate;
    uint16_t NetworkId;
    uint16_t TransportStreamId;
  } TStorageTransportStreamStruct;

  /**
  * Service structure. Used to represent a Service from the storage collections.
  */
  typedef struct Service {
    Service(uint16_t net, uint16_t ts, uint16_t id, std::string name)
    : NetworkId(net),
      TransportStreamId(ts),
      ServiceId(id),
      ServiceName(std::move(name))
    {
      // Empty
    }
    uint16_t NetworkId;
    uint16_t TransportStreamId;
    uint16_t ServiceId;
    std::string ServiceName;
  } ServiceStruct;

  typedef struct Event {
    uint16_t NetworkId;
    uint16_t TransportStreamId;
    uint16_t ServiceId;
    uint16_t EventId;
    uint64_t StartTime;
    uint32_t Duration;
    std::string EventName;
    std::string EventText;
  } EventStruct;

  enum {
    NIT_TIMEOUT = 15,
    NIT_OTHER_TIMEOUT = 15,
    SDT_TIMEOUT = 5,
    SDT_OTHER_TIMEOUT = 15,
    BAT_TIMEOUT = 15,
    EIT_PF_TIMEOUT = 5,
    EIT_PF_OTHER_TIMEOUT = 15,
    EIT_8_DAY_SCHED_TIMEOUT = 15,
    EIT_PAST_8_DAY_SCHED_TIMEOUT = 60,
  };

  typedef struct InbandTableInfo {
    InbandTableInfo(uint16_t p, uint8_t id, uint16_t extId)
    : Pid(p),
      ExtensionId(extId),
      TableId(id)
    {
      // Empty
    }
    uint16_t Pid;
    uint16_t ExtensionId;
    uint8_t  TableId;
  } InbandTableInfoStruct;

  enum TDvbScanState {
    SCAN_STOPPED,
    SCAN_STARTING,
    SCAN_IN_PROGRESS_FAST,
    SCAN_IN_PROGRESS_BKGD,
    SCAN_COMPLETED,
    SCAN_FAILED
  };

  struct TDvbSiTableStatus {
    bool NitAcquired;
    bool BatAcquired;
    bool SdtAcquired;
    bool EitPfAcquired;
    bool EitAcquired;
  };

  struct TDvbScanStatus {
    TDvbScanState ScanState;
    std::vector<std::pair<uint32_t, TDvbSiTableStatus>> TsList;
  };
}
#endif // TDVBSTORAGENAMESPACE_H
