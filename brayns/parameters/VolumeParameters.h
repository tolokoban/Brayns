/* Copyright (c) 2015-2016, EPFL/Blue Brain Project
 * All rights reserved. Do not distribute without permission.
 * Responsible Author: Cyrille Favreau <cyrille.favreau@epfl.ch>
 *
 * This file is part of Brayns <https://github.com/BlueBrain/Brayns>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef VOLUMEPARAMETERS_H
#define VOLUMEPARAMETERS_H

#include "AbstractParameters.h"

namespace brayns
{

class VolumeParameters final : public AbstractParameters
{
public:
    VolumeParameters();

    /** @copydoc AbstractParameters::print */
    void print( ) final;

    /** File containing volume data */
    const std::string& getFilename() const { return _filename; }

    /** Volume dimension  */
    const Vector3ui& getDimensions() const { return _dimensions; }

    /** Volume scale  */
    const Vector3f& getScale() const { return _scale; }

    /** Volume position */
    const Vector3f& getPosition() const { return _position; }

    /** Volume epsilon */
    void setSamplesPerRay( const size_t spr ) { _spr = spr; }
    const float& getSamplesPerRay() const { return _spr; }

protected:

    bool _parse( const po::variables_map& vm ) final;

    std::string _filename;
    Vector3ui _dimensions;
    Vector3f _scale;
    Vector3f _position;
    float _spr;

};

}
#endif // VOLUMEPARAMETERS_H
