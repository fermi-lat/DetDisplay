
#ifndef DETDISPLAYSVC_H
#define DETDISPLAYSVC_H 1

/** 
 * @class DetDisplaySvc
 *
 * @brief Load IGuiTools 
 *
 * 
 * @author Heather Kelly 
 *
 * $Header: /nfs/slac/g/glast/ground/cvs/TkrUtil/src/TkrGeometrySvc.h,v 1.34 2012/01/05 23:55:42 jrb Exp $
 */

#include "GuiSvc/IGuiTool.h"
#include "GaudiKernel/Service.h"

class DetDisplaySvc : public Service
{
public:
    
    DetDisplaySvc(const std::string& name, ISvcLocator* pSvcLocator); 
    virtual ~DetDisplaySvc() {}
    
    StatusCode initialize();
    StatusCode finalize();
    
    //StatusCode queryInterface(const InterfaceID& riid, void** ppvUnknown);

   //static const InterfaceID& interfaceID() {
    //    return IDetDisplaySvc::interfaceID(); 
   // }
    /// return the service type
   // const InterfaceID& type() const;

private:

    IGuiTool *m_detDisplayTool;
    IGuiTool * m_mcTool;
    IGuiTool *m_stripTool;


};

#endif // DETDISPLAYSVC_H
