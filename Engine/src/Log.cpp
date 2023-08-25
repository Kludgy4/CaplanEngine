#include "engpch.h"
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/daily_file_sink.h"

std::shared_ptr<spdlog::logger> Log::engineLogger;
std::shared_ptr<spdlog::logger> Log::clientLogger;

void Log::InitLoggers() {
	
	spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] [T%t] [P%p] %v");
	
	auto sinks = std::vector<spdlog::sink_ptr>();
	sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	sinks.emplace_back(std::make_shared<spdlog::sinks::daily_file_sink_mt>("logs/log_file", 03, 00));

    #define MAKE_LOGGER(name) make_shared<spdlog::logger>(name, sinks.begin(), sinks.end());
	Log::engineLogger = MAKE_LOGGER("Engine Logger");
	Log::clientLogger = MAKE_LOGGER("Client Logger");
}
