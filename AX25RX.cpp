/*
 *   Copyright (C) 2020 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "Config.h"
#include "Globals.h"
#include "AX25RX.h"

CAX25RX::CAX25RX() :
m_demod1(1U),
m_demod2(2U),
m_demod3(3U)
{
}

void CAX25RX::samples(const q15_t* samples, uint8_t length)
{
  for (uint8_t i = 0U; i < length; i++) {
    q15_t sample = samples[i];

    m_demod1.process(sample);
    m_demod2.process(sample);
    m_demod3.process(sample);
  }
}

