#include<iostream>

class Log
{
public:

	enum LevelA
	{
		// cases are under Log nameSpace instead of LevelA
		LevelError = 0, LevelWarning, LevelInfo
	};

	enum LevelB
	{
		// cases are under Log nameSpace instead of LevelB
		LevelErrorB = 0, LevelWarningB, LevelInfoB
	};

	enum LevelC
	{
		// Cause redefinition compile issue
		// cases are under Log nameSpace instead of Level
		LevelError = 0, LevelWarning, LevelInfo
	};

	enum class LevelD : int
	{
		// cases are under LevelD nameSpace instead of Log
		LevelError, LevelWarning, LevelInfo
	};

	enum class LevelE : int
	{
		// cases are under LevelE nameSpace instead of Log
		LevelError, LevelWarning, LevelInfo
	};

private:
	LevelA m_LogLevel = LevelInfo;

public:
	void SetLevel(LevelA level)
	{
		m_LogLevel = level;
	}

	void Error(const char* message)
	{
		if (m_LogLevel >= LevelError)
			std::cout << "[ERROR]:" << message << std::endl;
	}

	void Warn(const char* message)
	{
		if (m_LogLevel >= LevelWarning)
			std::cout << "[WARNING]:" << message << std::endl;
	}

	void Info(const char* message)
	{
		if (m_LogLevel >= LevelInfo)
			std::cout << "[INFO]:" << message << std::endl;
	}
};


int main()
{
	Log log;
	log.SetLevel(Log::LevelWarning);
	log.Warn("Hello");
	log.Error("Hello");
	log.Info("Hello");

	if (Log::LevelWarning == Log::LevelWarning)
	{
		log.Info("Two normal enum can be compared");
	}

	if (Log::LevelD::LevelError == Log::LevelE::LevelError)
	{
		// Even with the enum type defined, still compling error
		// no operator matchs '==' for different enum
	}

}