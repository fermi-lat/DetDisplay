/** @file CompositeMedium.h
     @brief  implementation of class CompositeMedium

     $Header: /nfs/slac/g/glast/ground/cvs/DetDisplay/src/Medium.h,v 1.1 2003/07/04 22:08:31 burnett Exp $
*/

#include "CompositeMedium.h"

#include "gui/DisplayRep.h"

#include "geometry/Shape.h"
#include "geometry/Volume.h"
#include <algorithm>

CompositeMedium::CompositeMedium(Medium* prnt, Shape* vol, const char* matName)
: Medium(prnt, vol, matName)
{}

CompositeMedium::~CompositeMedium()
{
    deleteInnerMedia();
    if(_parent) {
        _parent->removeMedium(this);
    }
}
////////////////////////////////0/////////////////////////////////////////////
//                manage inner media
void CompositeMedium::deleteInnerMedia()
{
    for(reverse_iterator it=rbegin(); it !=rend(); ++it)
	delete *it;
}

Medium& CompositeMedium::addMedium ( Medium* nextMedium)
{
    push_back(nextMedium);
    nextMedium->setParent(this);
    return *nextMedium;
}

Medium& CompositeMedium::removeMedium (Medium* oldMedium)
{
    iterator it = std::find(begin(), end(), oldMedium);
    if( it != end())
	 erase(it);
    return *oldMedium;
}
const char* CompositeMedium::nameOf() const {
  return "CompositeMedium";
}

int CompositeMedium::isComposite() const {
  return 1;
}

///////////////////////////////////////////////////////////////////////////////
//                       coordinate transformation
GeomObject&
CompositeMedium::transform(const CoordTransform& T)
{
    Medium::transform(T);
    for(iterator it=begin(); it !=end(); ++it)
	(*it)->transform(T);
    return *this;
}
void CompositeMedium::createDetectorView(gui::DisplayRep& v)
{

    Medium::createDetectorView(v);
    for(iterator it=begin(); it !=end(); ++it )
       (*it)->createDetectorView(v.nested());
}

