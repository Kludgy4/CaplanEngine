#include "engpch.h"
#include "Log.h"
//#include "spdlog/async.h"
#include "spdlog/sinks/stdout_color_sinks.h"
//#include "spdlog/sinks/basic_file_sink.h"

#define MAKE_LOGGER(name) std::make_shared<spdlog::logger>(spdlog::stdout_color_mt(name));

void Log::InitLoggers() {
	spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] [T%t] [P%p] %v");

	Log::engineLogger = MAKE_LOGGER("Engine Logger");
	Log::clientLogger = MAKE_LOGGER("Client Logger");
}
