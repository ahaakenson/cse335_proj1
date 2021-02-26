/**
 * \file Decor.h
 *
 * \author Andrew Haakenson
 *
 * Base class for roads and rivers.  Represents background of game.
 */

#pragma once
#include <memory>
#include "Item.h"
#include "XmlNode.h"
#include "Game.h"

 /**
  * Base class for roads and rivers.  Represents background of game.
  */
class CDecor : public CItem
{
public:
	/// Default contructor (disabled)
	CDecor() = delete;

	/// Copy constructor (disabled)
	CDecor(const CDecor&) = delete;

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	CDecor(CGame* game, const std::wstring& filename);

	virtual void Draw(Gdiplus::Graphics* graphics);

private:
	/// How many times decor repeats in x direction
	int mRepeatX = 1;
	/// How many times decor repeats in y direction
	int mRepeatY = 1;

};

