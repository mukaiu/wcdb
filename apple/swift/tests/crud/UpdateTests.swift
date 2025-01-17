/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import XCTest
import WCDB

class UpdateTests: CRUDTestCase {

    var update: Update!

    override func setUp() {
        super.setUp()

        let optionalUpdate = WCDBAssertNoThrowReturned(
            try database.prepareUpdate(table: TestObject.name, on: TestObject.Properties.variable2)
        )
        XCTAssertNotNil(optionalUpdate)
        update = optionalUpdate!
    }

    func testUpdate() {
        // Give
        let object = TestObject()
        object.variable2 = self.name
        // When
        XCTAssertNoThrow(try update.execute(with: object))
        // Then
        let results: [TestObject] = WCDBAssertNoThrowReturned(
            try database.getObjects(fromTable: TestObject.name),
            whenFailed: [TestObject]()
        )
        XCTAssertEqual(Array(repeating: self.name, count: preInsertedObjects.count), results.map({
            XCTAssertNotNil($0.variable2)
            return $0.variable2!
        }))
    }

    func testConditionalUpdate() {
        // Give
        let object = TestObject()
        object.variable2 = self.name
        // When
        XCTAssertNoThrow(try update.where(TestObject.Properties.variable1 == 1).execute(with: object))
        // Then
        let result: TestObject? = WCDBAssertNoThrowReturned(
            try database.getObject(fromTable: TestObject.name, where: TestObject.Properties.variable1 == 1)
        )
        XCTAssertNotNil(result)
        XCTAssertEqual(self.name, result!.variable2)
    }

    func testOrderedUpdate() {
        // Give
        let object = TestObject()
        object.variable2 = self.name
        let order = TestObject.Properties.variable1.order(.descending)
        // When
        XCTAssertNoThrow(try update.order(by: order).limit(1).execute(with: object))
        // Then
        let result: TestObject? = WCDBAssertNoThrowReturned(
            try database.getObject(fromTable: TestObject.name, where: TestObject.Properties.variable1 == 2)
        )
        XCTAssertNotNil(result)
        XCTAssertEqual(self.name, result!.variable2)
    }

    func testLimitedUpdate() {
        // Give
        let object = TestObject()
        object.variable2 = self.name
        // When
        XCTAssertNoThrow(try update.limit(1).execute(with: object))
        // Then
        let results: [TestObject] = WCDBAssertNoThrowReturned(
            try database.getObjects(fromTable: TestObject.name)
        )
        XCTAssertEqual(results[0].variable2, self.name)
        XCTAssertEqual(results[1], preInsertedObjects[1])
    }

    func testOffsetUpdate() {
        // Give
        let object = TestObject()
        object.variable2 = self.name
        // When
        XCTAssertNoThrow(try update.limit(1, offset: 1).execute(with: object))
        // Then
        let results: [TestObject] = WCDBAssertNoThrowReturned(try database.getObjects(fromTable: TestObject.name))
        XCTAssertEqual(results[0], preInsertedObjects[0])
        XCTAssertEqual(results[1].variable2, self.name)
    }

    func testLimitFromToUpdate() {
        // Give
        let object = TestObject()
        object.variable2 = self.name
        // When
        XCTAssertNoThrow(try update.limit(from: 1, to: 2).execute(with: object))
        // Then
        let results: [TestObject] = WCDBAssertNoThrowReturned(try database.getObjects(fromTable: TestObject.name))
        XCTAssertEqual(results[0], preInsertedObjects[0])
        XCTAssertEqual(results[1].variable2, self.name)
    }

    func testUpdateChanges() {
        // Give
        let object = TestObject()
        object.variable2 = self.name
        // When
        XCTAssertNoThrow(try update.execute(with: object))
        // Then
        XCTAssertEqual(update.changes, preInsertedObjects.count)
    }
}
