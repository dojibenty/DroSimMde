#pragma once

#include <variant>

#ifndef RETURNCODE_H
#define RETURNCODE_H

enum class FormalCode {
    proceed,
    local_stop,
    simulation_success,
    simulation_fail,
    other
};

enum class CustomCode {
    low_battery,
    objective_found
};

// TODO cast quand selection du variant => eviter (perfs)

class ReturnCode {
    std::variant<FormalCode, CustomCode> code_;
    
public:
    ReturnCode(FormalCode fc) : code_(fc) {}
    ReturnCode(CustomCode cc) : code_(cc) {}

    bool isFormal() const {
        return std::holds_alternative<FormalCode>(code_);
    }

    bool isCustom() const {
        return std::holds_alternative<CustomCode>(code_);
    }

    FormalCode getFormal() const {
        return std::get<FormalCode>(code_);
    }

    CustomCode getCustom() const {
        return std::get<CustomCode>(code_);
    }

    void customToFormal() {
        switch(getCustom()) {
        case CustomCode::low_battery:
            code_ = FormalCode::local_stop;
            break;
        case CustomCode::objective_found:
            code_ = FormalCode::simulation_success;
            break;
        }

        code_ = FormalCode::other;
    }
};

#endif