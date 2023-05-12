<xsl:stylesheet version="1.0"
xmlns:xsl = "http://www.w3.org/1999/XSL/Transform">
    <xsl:template match = "/frands">
        <html>
            <body>
                <h2>
                    Frands list
                </h2>
                <table border="2" width="700px" height="500px">
                    <tr>
                        <th>
                            Name
                        </th>
                        <th>
                            Age
                        </th>
                        <th>
                            DOB
                        </th>
                    </tr>
                    <xsl:for-each select="frand">
                        <tr>
                            <td><xsl:value-of select = "name"/></td>
                            <td><xsl:value-of select = "age"/></td>
                            <td><xsl:value-of select = "DOB"/></td>
                        </tr>
                    </xsl:for-each>
                </table>
            </body>
        </html>
    </xsl:template>
</xsl:stylesheet>