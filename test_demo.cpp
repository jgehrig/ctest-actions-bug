#include <QtTest/QtTest>

class TestDemo : public QObject
{
	Q_OBJECT

private slots:
	void PassingTestCase() noexcept;
	void FailingTestCase() noexcept;
};

void TestDemo::PassingTestCase() noexcept
{
	QVERIFY(true);
}

void TestDemo::FailingTestCase() noexcept
{
	QVERIFY(false);
}

QTEST_MAIN(TestDemo)
#include "test_demo.moc"
