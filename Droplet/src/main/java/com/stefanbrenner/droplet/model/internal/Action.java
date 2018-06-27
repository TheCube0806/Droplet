/*******************************************************************************
 * Project: Droplet - Toolkit for Liquid Art Photographers
 * Copyright (C) 2012 Stefan Brenner
 *
 * This file is part of Droplet.
 *
 * Droplet is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Droplet is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Droplet. If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/
package com.stefanbrenner.droplet.model.internal;

import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlRootElement;

import com.stefanbrenner.droplet.model.IAction;

import lombok.Getter;
import lombok.NoArgsConstructor;

/**
 * @author Stefan Brenner
 */
@XmlRootElement(name = "Action")
@Getter
@NoArgsConstructor
public class Action extends AbstractModelObject implements IAction {
	
	private static final long serialVersionUID = 1L;
	
	@XmlAttribute(name = "Enabled")
	private boolean enabled = true;
	
	@XmlAttribute(name = "Offset")
	private Integer offset = 0;
	
	@Override
	public void setEnabled(final boolean enabled) {
		firePropertyChange(IAction.PROPERTY_ENABLED, this.enabled, this.enabled = enabled);
	}
	
	@Override
	public void setOffset(final Integer offset) {
		firePropertyChange(IAction.PROPERTY_OFFSET, this.offset, this.offset = offset);
	}
	
	@Override
	public void addOffset(final Integer offset) {
		firePropertyChange(IAction.PROPERTY_OFFSET, this.offset, this.offset += offset);
	}

	@Override
	public boolean isEnabled() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public Integer getOffset() {
		// TODO Auto-generated method stub
		return null;
	}
	
}
