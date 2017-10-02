#ifndef NIGHTMODEEXTENSION_H
#define NIGHTMODEEXTENSION_H

#include <QtWaylandClient/qwaylandclientextension.h>
#include "qwayland-nightmode.h" //generated?

class NightModeExtension : public QWaylandClientExtensionTemplate<NightModeExtension>
        , public QtWayland::qt_night_mode
{
    Q_OBJECT
    Q_PROPERTY(bool enabled READ isEnabled NOTIFY enabledChanged)
public:
    NightModeExtension();
    void night_mode_set_night_mode(uint32_t state) override;
    bool isEnabled() const { return m_enabled; }

signals:
    void enabledChanged();

private:
    bool m_enabled = false;
};

#endif // NIGHTMODEEXTENSION_H
