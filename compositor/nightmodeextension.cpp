#include "nightmodeextension.h"

NightModeExtension::NightModeExtension(QWaylandCompositor *compositor)
    : QWaylandCompositorExtensionTemplate(compositor)
{
}

void NightModeExtension::initialize()
{
    QWaylandCompositorExtensionTemplate::initialize();
    auto compositor = static_cast<QWaylandCompositor *>(extensionContainer());
    const int version = 1;
    init(compositor->display(), version);
}

void NightModeExtension::setEnabled(bool enabled)
{
    if (enabled == m_enabled)
        return;
    m_enabled = enabled;

    for (auto resource : resourceMap())
        send_set_night_mode(resource->handle, enabled ? state_night : state_day);

    emit enabledChanged();
}

void NightModeExtension::night_mode_bind_resource(QtWaylandServer::qt_night_mode::Resource *resource)
{
    send_set_night_mode(resource->handle, m_enabled ? state_night : state_day);
}
