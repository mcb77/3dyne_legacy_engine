/* 
 * 3dyne Legacy Engine GPL Source Code
 * 
 * Copyright (C) 1996-2012 Matthias C. Berger & Simon Berger.
 * 
 * This file is part of the 3dyne Legacy Engine GPL Source Code ("3dyne Legacy
 * Engine Source Code").
 *   
 * 3dyne Legacy Engine Source Code is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 * 
 * 3dyne Legacy Engine Source Code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * 3dyne Legacy Engine Source Code.  If not, see
 * <http://www.gnu.org/licenses/>.
 * 
 * In addition, the 3dyne Legacy Engine Source Code is also subject to certain
 * additional terms. You should have received a copy of these additional terms
 * immediately following the terms and conditions of the GNU General Public
 * License which accompanied the 3dyne Legacy Engine Source Code.
 * 
 * Contributors:
 *     Matthias C. Berger (mcb77@gmx.de) - initial API and implementation
 *     Simon Berger (simberger@gmail.com) - initial API and implementation
 */



// cl_gfx.c

#include "cl_state.h"
#include "cl_head.h"
#include "cl_defs.h"
#include "lib_math.h"
#include "shock.h"

void CL_CreateGfxFromEvent( byte_iter_t *bi )
{
	// all gfx need these
	vec3d_t		origin;
	gfxStyle		gfx_style;

	gfx_style = (gfxStyle)ByteIter_Unpacki( bi );
	ByteIter_Unpack3fv( bi, origin );
	
	if ( gfx_style == gfxStyle_teleport_send )
	{
		cl_ati_t	*expl;

		expl = CL_CreateExplosion( origin, explosionStyle_teleport_send );
		U_ListInsertAtHead( &cl_ati_wakeup_list, expl );
		
	}
	else if ( gfx_style == gfxStyle_teleport_recv )
	{
		cl_ati_t	*expl;

		expl = CL_CreateExplosion( origin, explosionStyle_teleport_recv );
		U_ListInsertAtHead( &cl_ati_wakeup_list, expl );
	}
}
