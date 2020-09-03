#include "datasource_flightrecorder.h"
#include <assert.h>

namespace Editor
{
	DataSourceFlightRecorder::DataSourceFlightRecorder(Emulation::FlightRecorder* inFlightRecorder)
		: m_FlightRecorder(inFlightRecorder)
	{

	}


	DataSourceFlightRecorder::~DataSourceFlightRecorder()
	{

	}


	void DataSourceFlightRecorder::Lock()
	{
		assert(m_FlightRecorder != nullptr);
		m_FlightRecorder->Lock();
	}


	void DataSourceFlightRecorder::Unlock()
	{
		assert(m_FlightRecorder != nullptr);
		m_FlightRecorder->Unlock();
	}

	
	const Emulation::FlightRecorder::Frame& DataSourceFlightRecorder::operator [](unsigned int inIndex) const
	{
		assert(m_FlightRecorder != nullptr);
		assert(inIndex < m_FlightRecorder->GetCapacity());

		return m_FlightRecorder->GetFrame(inIndex);
	}


	const int DataSourceFlightRecorder::GetSize() const
	{
		assert(m_FlightRecorder != nullptr);
		return static_cast<int>(m_FlightRecorder->GetCapacity());
	}


	const unsigned int DataSourceFlightRecorder::GetNewestRecordingIndex() const
	{
		assert(m_FlightRecorder != nullptr);

		unsigned int index = m_FlightRecorder->RecordedFrameCount();
		if (index >= m_FlightRecorder->GetCapacity())
			return m_FlightRecorder->GetCapacity() - 1;

		return static_cast<int>(m_FlightRecorder->RecordedFrameCount());
	}
}
