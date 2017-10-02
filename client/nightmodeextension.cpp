#include "nightmodeextension.h"
#include <QDebug>

NightModeExtension::NightModeExtension()
    : QWaylandClientExtensionTemplate(/* Supported protocol version */ 1 )
{
}

void NightModeExtension::night_mode_set_night_mode(uint32_t state)
{
    if (m_enabled == state)
        return;
    m_enabled = state == state_night;
    emit enabledChanged();
}
