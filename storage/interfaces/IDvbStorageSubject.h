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
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef IDVBSTORAGESUBJECT_H
#define IDVBSTORAGESUBJECT_H

#include "IDvbStorageObserver.h"
#include "TDvbStorageNamespace.h"

class IDvbStorageSubject
{
public:
  virtual void RegisterDvbStorageObserver(IDvbStorageObserver* observerObject) = 0;
  virtual void RemoveDvbStorageObserver(IDvbStorageObserver* observerObject) = 0;
  virtual void NotifyDvbStorageTuneObserver(const uint32_t& freq, const TDvbStorageNamespace::TModulationMode& mod,
    const uint32_t& symbol) = 0;
  virtual void NotifyDvbStorageUnTuneObserver() = 0;
};

#endif // IDVBSTORAGESUBJECT_H
