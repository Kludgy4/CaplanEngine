#pragma once

#include "spdlog/spdlog.h"

class Log {
public:
	static void InitLoggers();

	inline static std::shared_ptr<spdlog::logger> getEngineLogger() { return engineLogger; }
	inline static std::shared_ptr<spdlog::logger> getClientLogger() { return clientLogger; }

private:
	static std::shared_ptr<spdlog::logger> engineLogger;
	static std::shared_ptr<spdlog::logger> clientLogger;
};

#ifdef CP_DEBUG
	#define LOG_ENGINE_TRACE(...)    Log::getEngineLogger()->trace(__VA_ARGS__) 
	#define LOG_ENGINE_DEBUG(...)    Log::getEngineLogger()->debug(__VA_ARGS__) 
	#define LOG_ENGINE_INFO(...)     Log::getEngineLogger()->info(__VA_ARGS__) 
	#define LOG_ENGINE_WARN(...)     Log::getEngineLogger()->warn(__VA_ARGS__) 
	#define LOG_ENGINE_ERROR(...)    Log::getEngineLogger()->error(__VA_ARGS__) 
	#define LOG_ENGINE_CRITICAL(...) Log::getEngineLogger()->critical(__VA_ARGS__) 

	#define LOG_CLIENT_TRACE(...)    Log::getClientLogger()->trace(__VA_ARGS__) 
	#define LOG_CLIENT_DEBUG(...)    Log::getClientLogger()->debug(__VA_ARGS__) 
	#define LOG_CLIENT_INFO(...)     Log::getClientLogger()->info(__VA_ARGS__) 
	#define LOG_CLIENT_WARN(...)     Log::getClientLogger()->warn(__VA_ARGS__) 
	#define LOG_CLIENT_ERROR(...)    Log::getClientLogger()->error(__VA_ARGS__) 
	#define LOG_CLIENT_CRITICAL(...) Log::getClientLogger()->critical(__VA_ARGS__) 
#else
	#define LOG_ENGINE_TRACE(...)
	#define LOG_ENGINE_DEBUG(...)
	#define LOG_ENGINE_INFO(...)
	#define LOG_ENGINE_WARN(...)
	#define LOG_ENGINE_ERROR(...)
	#define LOG_ENGINE_CRITICAL(...)

	#define LOG_CLIENT_TRACE(...)
	#define LOG_CLIENT_DEBUG(...)
	#define LOG_CLIENT_INFO(...)
	#define LOG_CLIENT_WARN(...)
	#define LOG_CLIENT_ERROR(...)
	#define LOG_CLIENT_CRITICAL(...)
#endif
