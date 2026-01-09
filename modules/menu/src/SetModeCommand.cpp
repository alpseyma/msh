#include "SetModeCommand.h"
#include "ModeManager.h"

SetModeCommand::SetModeCommand(SystemMode mode)
    : m_mode(mode) {}

void SetModeCommand::execute() {
    ModeManager::instance().setMode(m_mode);
}
