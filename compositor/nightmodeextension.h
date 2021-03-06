#ifndef NIGHTMODEEXTENSION_H
#define NIGHTMODEEXTENSION_H

#include <QtWaylandCompositor/QWaylandCompositorExtensionTemplate>
#include <QtWaylandCompositor/QWaylandQuickExtension>
#include <QtWaylandCompositor/QWaylandCompositor>
#include "qwayland-server-nightmode.h" // generated by qtwaylandscanner

class NightModeExtension : public QWaylandCompositorExtensionTemplate<NightModeExtension>
        , public QtWaylandServer::qt_night_mode
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)

public:
    NightModeExtension(QWaylandCompositor *compositor = nullptr);
    void initialize() override;
    void setEnabled(bool enabled);
    bool isEnabled() const { return m_enabled; }

signals:
    void enabledChanged();

protected:
    void night_mode_bind_resource(Resource *resource) override;

private:
    bool m_enabled = false;
};

Q_COMPOSITOR_DECLARE_QUICK_EXTENSION_CLASS(NightModeExtension)

#endif // NIGHTMODEEXTENSION_H
