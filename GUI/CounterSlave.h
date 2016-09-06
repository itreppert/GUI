#pragma once
namespace GUI {
	public ref class CounterSlave
	{
	public:
		int loopStart;
		int loopEnd;
		System::String^ threadName;
		bool ready = false;

		CounterSlave(int startValue, int endValue, System::String^ threadName)
		{
			loopStart = startValue;
			loopEnd = endValue;
			this->threadName = threadName;
		}

		virtual ~CounterSlave()
		{
		}

		/*1*/ void startWorking()
		{
			/*2*/   System::String^ threadName = System::Threading::Thread::CurrentThread->Name;

			for (int i = loopStart; i <= loopEnd; ++i)
			{
				System::Windows::Forms::Application::DoEvents();
				log(i.ToString());
			}
			ready = true;
			System::Diagnostics::Debug::WriteLine(threadName + " thread terminating", threadName);
		}

		void log(System::String^ irgendwas)
		{
			System::Diagnostics::Debug::WriteLine(this->threadName + " did " + irgendwas);
		}

	};
}