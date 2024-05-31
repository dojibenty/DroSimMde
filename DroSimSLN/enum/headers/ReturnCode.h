#pragma once

#ifndef RETURNCODE_H
#define RETURNCODE_H

enum class ReturnCode {
    proceed,
    local_stop,
    simulation_success,
    simulation_fail,
    other
};

#endif;
