#ifndef COIN_SOGROUP_H
#define COIN_SOGROUP_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2003 by Systems in Motion.  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Systems in Motion about acquiring
 *  a Coin Professional Edition License.
 *
 *  See <URL:http://www.coin3d.org> for  more information.
 *
 *  Systems in Motion, Teknobyen, Abels Gate 5, 7030 Trondheim, NORWAY.
 *  <URL:http://www.sim.no>.
 *
\**************************************************************************/

#include <Inventor/nodes/SoSubNode.h>

class SoGroupP;

#ifdef __PIVY__
%rename(SoGroup_i) SoGroup::SoGroup(int nchildren);

%feature("shadow") SoGroup::SoGroup %{
def __init__(self,*args):
   if len(args) == 1:
      self.this = apply(_pivy.new_SoGroup_i,args)
      self.thisown = 1
      return
   self.this = apply(_pivy.new_SoGroup,args)
   self.thisown = 1
%}

%rename(removeChild_nod) SoGroup::removeChild(SoNode * const child);

%feature("shadow") SoGroup::removeChild(const int childindex) %{
def removeChild(*args):
   if isinstance(args[1], SoNode):
      return apply(_pivy.SoGroup_removeChild_nod,args)
   return apply(_pivy.SoGroup_removeChild,args)
%}

%rename(replaceChild_nod_nod) SoGroup::replaceChild(SoNode * const oldchild, SoNode * const newchild);

%feature("shadow") SoGroup::replaceChild(const int index, SoNode * const newchild) %{
def replaceChild(*args):
   if isinstance(args[1], SoNode):
      return apply(_pivy.SoGroup_replaceChild_nod_nod,args)
   return apply(_pivy.SoGroup_replaceChild,args)
%}
#endif

class COIN_DLL_API SoGroup : public SoNode {
  typedef SoNode inherited;

  SO_NODE_HEADER(SoGroup);

public:
  static void initClass(void);
  SoGroup(void);

  SoGroup(int nchildren);
 
  virtual void addChild(SoNode * node);
  virtual void insertChild(SoNode * child, int newchildindex);
  virtual SoNode * getChild(int index) const;
  virtual int findChild(const SoNode * node) const;
  virtual int getNumChildren(void) const;
  virtual void removeChild(int childindex);
  virtual void removeChild(SoNode * child);
  virtual void removeAllChildren(void);
  virtual void replaceChild(int index, SoNode * newchild);
  virtual void replaceChild(SoNode * oldchild, SoNode * newchild);

  virtual void doAction(SoAction * action);
  virtual void GLRender(SoGLRenderAction * action);
  virtual void callback(SoCallbackAction * action);
  virtual void getBoundingBox(SoGetBoundingBoxAction * action);
  virtual void getMatrix(SoGetMatrixAction * action);
  virtual void handleEvent(SoHandleEventAction * action);
  virtual void pick(SoPickAction * action);
  virtual void search(SoSearchAction * action);
  virtual void write(SoWriteAction * action);
  virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);
  virtual void audioRender(SoAudioRenderAction * action);
  virtual SoChildList * getChildren(void) const;

protected:
  virtual ~SoGroup();

  virtual SbBool readInstance(SoInput * in, unsigned short flags);
  virtual SbBool readChildren(SoInput * in);

  virtual void copyContents(const SoFieldContainer * from,
                            SbBool copyconnections);

  SoChildList * children;

private:
  friend class SoUnknownNode; // Let SoUnknownNode access readChildren().
  SoGroupP * pimpl;
};

#endif // !COIN_SOGROUP_H